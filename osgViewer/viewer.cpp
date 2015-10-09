#include "viewer.h"
#include <QtGui/QOpenGLFramebufferObject>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLFunctions>
#include <QtQuick/QQuickWindow>
#include <QtQuick/QSGSimpleTextureNode>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osg/Camera>
#include <osgGA/TrackballManipulator>

ViewerRenderer::ViewerRenderer(osgViewer::Viewer* osgViewer) : osgViewer(osgViewer)
{
}

void ViewerRenderer::render() {
    QOpenGLContext::currentContext()->functions()->glUseProgram(0);
    osgViewer->frame();
    update();
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
    osgViewer->setThreadingModel(osgViewer::ViewerBase::SingleThreaded);
    osgViewer->setUpViewerAsEmbeddedInWindow(0, 0, 1, 1);
    osgViewer->setSceneData(osgDB::readNodeFile("cow.osgt"));
    osgViewer->getCamera()->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    auto manipulator = new osgGA::TrackballManipulator;
    manipulator->setAllowThrow(false);
    osgViewer->setCameraManipulator(manipulator);
}

QQuickFramebufferObject::Renderer* Viewer::createRenderer() const
{
    return new ViewerRenderer(osgViewer);
}

void Viewer::saveScene(QString path)
{
    osgDB::writeNodeFile(*sceneData->toOsg(), path.toStdString());
}

void Viewer::setSceneData(Node* sceneData)
{
    if (sceneData == this->sceneData) return;
    this->sceneData = sceneData;
    osgViewer->setSceneData(sceneData->toOsg());
    emit sceneDataChanged(sceneData);
}

Camera* Viewer::getCamera()
{
    if (camera == nullptr) {
        camera = new Camera();
        camera->fromOsg(osgViewer->getCamera());
        camera->classBegin();
    }
    return camera;
}

void Viewer::setCamera(Camera *camera)
{
    if (this->camera == camera) return;
    this->camera = camera;
    osgViewer->setCamera(camera->toOsg());
    emit cameraChanged(camera);
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
}

void Viewer::mouseDoubleClickEvent(QMouseEvent* event)
{
    osgViewer->getEventQueue()->mouseDoubleButtonPress((float)event->x(), (float)event->y(), mouseButtonMask(event));
}

void Viewer::mouseMoveEvent(QMouseEvent *event)
{
    osgViewer->getEventQueue()->mouseMotion(event->localPos().x(), event->localPos().y());
}

void Viewer::mousePressEvent(QMouseEvent *event)
{
    osgViewer->getEventQueue()->mouseButtonPress(event->localPos().x(), event->localPos().y(), mouseButtonMask(event));
}

void Viewer::mouseReleaseEvent(QMouseEvent *event)
{
    osgViewer->getEventQueue()->mouseButtonRelease(event->localPos().x(), event->localPos().y(), mouseButtonMask(event));
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
