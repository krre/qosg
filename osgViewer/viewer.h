#pragma once
#include <osgViewer/Viewer>
#include <QtQuick/QQuickFramebufferObject>

class ViewerRenderer : public QQuickFramebufferObject::Renderer
{
public:
    ViewerRenderer(osg::ref_ptr<osgViewer::Viewer> osgViewer);
    void render();
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size);

private:
    osg::ref_ptr<osgViewer::Viewer> osgViewer;
};

class Viewer : public QQuickFramebufferObject
{
    Q_OBJECT

public:
    Viewer();
    Renderer* createRenderer() const;

protected:
    QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData* nodeData) override;

    void wheelEvent(QWheelEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    osgGA::GUIEventAdapter::MouseButtonMask mouseButtonMask(QMouseEvent *event);
    osg::ref_ptr<osgViewer::Viewer> osgViewer;
};
