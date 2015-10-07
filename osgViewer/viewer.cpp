#include "viewer.h"
#include <QtGui/QOpenGLFramebufferObject>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLFunctions>
#include <QtQuick/QQuickWindow>
#include <qsgsimpletexturenode.h>
#include <osgDB/ReadFile>
#include <osgGA/MultiTouchTrackballManipulator>
#include <osg/Camera>

ViewerRenderer::ViewerRenderer(osg::ref_ptr<osgViewer::Viewer> osgViewer) : osgViewer(osgViewer)
{

}

void ViewerRenderer::render() {
    qDebug() << "render";
    QOpenGLContext::currentContext()->functions()->glUseProgram(0);
    osgViewer->frame();
}

QOpenGLFramebufferObject *ViewerRenderer::createFramebufferObject(const QSize &size) {
    osgViewer->getCamera()->setViewport(0, 0, size.width(), size.height());
    osgViewer->getCamera()->setProjectionMatrixAsPerspective(30.0, (float) size.width() / size.height(), 0.1, 100);
    osgViewer->getEventQueue()->windowResize(0, 0, size.width(), size.height());

    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    format.setSamples(4);
    return new QOpenGLFramebufferObject(size, format);
}

Viewer::Viewer()
{
    setFlag(ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);

    osgViewer = new osgViewer::Viewer;
    osgViewer->setUpViewerAsEmbeddedInWindow(0, 0, 1, 1);
    osgViewer->setSceneData(osgDB::readNodeFile("cow.osgt"));
    osgViewer->setCameraManipulator(new osgGA::MultiTouchTrackballManipulator);
    osgViewer->getCamera()->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    osgViewer->getCamera()->setClearColor(osg::Vec4(0.5f, 0.5f, 0.5f, 1.0f));
}

QQuickFramebufferObject::Renderer* Viewer::createRenderer() const
{
    return new ViewerRenderer(osgViewer);
}

// Hack to flip texture node vertically
QSGNode* Viewer::updatePaintNode(QSGNode* node, QQuickItem::UpdatePaintNodeData* nodeData)
{
    if (!node) {
        node = QQuickFramebufferObject::updatePaintNode(node, nodeData);
        QSGSimpleTextureNode* n = static_cast<QSGSimpleTextureNode*>(node);
        if (n) {
            n->setTextureCoordinatesTransform(QSGSimpleTextureNode::MirrorVertically);
        }
        return node;
    }
    return QQuickFramebufferObject::updatePaintNode(node, nodeData);
}

void Viewer::wheelEvent(QWheelEvent *event)
{
    osgViewer->getEventQueue()->mouseScroll(event->delta() < 0 ? osgGA::GUIEventAdapter::SCROLL_UP : osgGA::GUIEventAdapter::SCROLL_DOWN);
    update();
}

void Viewer::mouseDoubleClickEvent(QMouseEvent* event)
{
    qDebug() << "mouseDoubleClickEvent" << event;
    osgGA::GUIEventAdapter::MouseButtonMask button;

    if ( Qt::LeftButton == event->button() )
        button = osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON;
    else if ( Qt::RightButton == event->button() )
        button = osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON;
    else if ( Qt::MidButton == event->button() )
        button = osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON;
    else
        return;

    osgViewer->getEventQueue()->mouseDoubleButtonPress((float)event->x(), (float)event->y(), button);
}

void Viewer::mouseMoveEvent(QMouseEvent *event)
{
//    qDebug() << "mouseMoveEvent" << event;
    osgViewer->getEventQueue()->mouseMotion((float)event->x(), (float)event->y());
}

void Viewer::mousePressEvent(QMouseEvent *event)
{
//    qDebug() << "mousePressEvent" << event;
    osgViewer->getEventQueue()->mouseButtonPress((float)event->x(), (float)event->y(), mouseButtonMask(event));
}

void Viewer::mouseReleaseEvent(QMouseEvent *event)
{
//    qDebug() << "mouseReleaseEvent" << event;
    osgViewer->getEventQueue()->mouseButtonRelease((float)event->x(), (float)event->y(), mouseButtonMask(event));
}

osgGA::GUIEventAdapter::MouseButtonMask Viewer::mouseButtonMask(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        return osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON;
    } else if (event->button() == Qt::RightButton) {
        return osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON;
    } else {
        return osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON;
    }
}
