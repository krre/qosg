#include "viewer.h"
#include "../osgGA/pickhandler.h"
#include <QtGui/QOpenGLFramebufferObject>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLFunctions>
#include <QtQuick/QQuickWindow>
#include <QtQuick/QSGSimpleTextureNode>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osg/Camera>

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

    osgViewer->setThreadingModel(osgViewer::ViewerBase::SingleThreaded);
    osg::GraphicsContext* gc = osgViewer->setUpViewerAsEmbeddedInWindow(0, 0, 1, 1);
    osgViewer->getEventQueue()->setGraphicsContext(gc);
    osgViewer->getCamera()->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    osgViewer->setCameraManipulator(manipulator);
    PickHandler* pickHandler = new PickHandler();
    osgViewer->addEventHandler(pickHandler);
    setAllowThrow(false);
    connect(pickHandler, SIGNAL(picked(const QString&)), this, SIGNAL(picked(const QString&)));
}

QQuickFramebufferObject::Renderer* Viewer::createRenderer() const
{
    return new ViewerRenderer(osgViewer.get());
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
    if (camera.isNull()) {
        camera = QSharedPointer<Camera>(new Camera());
        camera->fromOsg(osgViewer->getCamera());
    }
    return camera.data();
}

void Viewer::setCamera(Camera *camera)
{
    if (this->camera == camera) return;
    this->camera = QSharedPointer<Camera>(camera);
    osgViewer->setCamera(camera->toOsg());
    emit cameraChanged(camera);
}

void Viewer::setAllowThrow(bool allowThrow)
{
    if (manipulator->getAllowThrow() == allowThrow) return;
    manipulator->setAllowThrow(allowThrow);
    emit allowThrowChanged(allowThrow);
}

void Viewer::setInfiniteRender(bool infiniteRender)
{
    if (m_infiniteRender == infiniteRender) return;
    m_infiniteRender = infiniteRender;
    emit infiniteRenderChanged(infiniteRender);
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

void Viewer::wheelEvent(QWheelEvent* event)
{
    osgViewer->getEventQueue()->mouseScroll(event->delta() < 0 ? osgGA::GUIEventAdapter::SCROLL_UP : osgGA::GUIEventAdapter::SCROLL_DOWN);
}

void Viewer::mouseDoubleClickEvent(QMouseEvent* event)
{
    osgViewer->getEventQueue()->mouseDoubleButtonPress((float)event->x(), (float)event->y(), mouseButtonMask(event));
}

void Viewer::mouseMoveEvent(QMouseEvent* event)
{
    osgViewer->getEventQueue()->mouseMotion(event->localPos().x(), event->localPos().y());
}

void Viewer::mousePressEvent(QMouseEvent* event)
{
    osgViewer->getEventQueue()->mouseButtonPress(event->localPos().x(), event->localPos().y(), mouseButtonMask(event));
}

void Viewer::mouseReleaseEvent(QMouseEvent* event)
{
    osgViewer->getEventQueue()->mouseButtonRelease(event->localPos().x(), event->localPos().y(), mouseButtonMask(event));
}

osgGA::GUIEventAdapter::MouseButtonMask Viewer::mouseButtonMask(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        return osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON;
    } else if (event->button() == Qt::RightButton) {
        return osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON;
    } else {
        return osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON;
    }
}
