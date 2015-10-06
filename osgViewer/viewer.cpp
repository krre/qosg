#include "viewer.h"
#include "texturenode.h"
#include <QtQuick>
#include <osg/ShapeDrawable>
#include <osgDB/ReadFile>
#include <osgGA/MultiTouchTrackballManipulator>
#include <osg/Camera>
#include <osgViewer/Renderer>
#include <QOpenGLContext>

QList<QThread*> Viewer::threads;

Viewer::Viewer()
{
    setFlag(ItemHasContents, true);
}

void Viewer::ready()
{
    m_renderThread->surface = new QOffscreenSurface();
    m_renderThread->surface->setFormat(m_renderThread->context->format());
    m_renderThread->surface->create();

    m_renderThread->moveToThread(m_renderThread);

    connect(window(), SIGNAL(sceneGraphInvalidated()), m_renderThread, SLOT(shutDown()), Qt::QueuedConnection);

    m_renderThread->start();
    update();
}

QSGNode* Viewer::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*)
{
    TextureNode* node = static_cast<TextureNode*>(oldNode);

    if (!m_renderThread) {
        viewer = new osgViewer::Viewer;
        viewer->setSceneData(osgDB::readNodeFile("cow.osgt"));
        viewer->setCameraManipulator(new osgGA::MultiTouchTrackballManipulator);
        viewer->setUpViewerAsEmbeddedInWindow(0, 0, width(), height());

        osg::Camera* camera = viewer->getCamera();
        camera->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
        camera->setNearFarRatio(zNearFarRatio);
        camera->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera->setClearColor(color);

        fboTexture = new osg::Texture2D();
        fboTexture->setTextureSize(width(), height());
        fboTexture->setInternalFormat(GL_RGBA);
        fboTexture->setFilter(osg::Texture2D::MIN_FILTER,osg::Texture2D::LINEAR);
        fboTexture->setFilter(osg::Texture2D::MAG_FILTER,osg::Texture2D::LINEAR);
        fboTexture->apply(*camera->getGraphicsContext()->getState());

        camera->attach(osg::Camera::COLOR_BUFFER, fboTexture, 0, 0);

        m_renderThread = new RenderThread(QSize(width(), height()), viewer, fboTexture);
    }

    viewer->getCamera()->setViewport(0, 0, width(), height());
    viewer->getCamera()->setProjectionMatrixAsPerspective(fov, width() / height(), zNear, zFar);
    viewer->getEventQueue()->windowResize(0, 0, width(), height());

    if (!m_renderThread->context) {
        QOpenGLContext *current = window()->openglContext();
        // Some GL implementations requres that the currently bound context is
        // made non-current before we set up sharing, so we doneCurrent here
        // and makeCurrent down below while setting up our own context.
        current->doneCurrent();

        m_renderThread->context = new QOpenGLContext();
        m_renderThread->context->setFormat(current->format());
        m_renderThread->context->setShareContext(current);
        m_renderThread->context->create();
        m_renderThread->context->moveToThread(m_renderThread);

        current->makeCurrent(window());

        QMetaObject::invokeMethod(this, "ready");
        return 0;
    }

    if (!node) {
        node = new TextureNode(window());

        connect(m_renderThread, SIGNAL(textureReady(int,QSize)), node, SLOT(newTexture(int,QSize)), Qt::DirectConnection);
        connect(node, SIGNAL(pendingNewTexture()), window(), SLOT(update()), Qt::QueuedConnection);
        connect(window(), SIGNAL(beforeRendering()), node, SLOT(prepareNode()), Qt::DirectConnection);
        connect(node, SIGNAL(textureInUse()), m_renderThread, SLOT(renderNext()), Qt::QueuedConnection);

        QMetaObject::invokeMethod(m_renderThread, "renderNext", Qt::QueuedConnection);
    }

    node->setRect(boundingRect());
    return node;
}
