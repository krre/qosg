#pragma once
#include <osgViewer/Viewer>
#include <osg/Node>
#include <QtQuick/QQuickFramebufferObject>
#include "../osg/node.h"
#include "../osg/camera.h"

class ViewerRenderer : public QQuickFramebufferObject::Renderer
{
public:
    ViewerRenderer(osgViewer::Viewer *osgViewer);
    void render();
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size);

private:
    osgViewer::Viewer* osgViewer;
};

class Viewer : public QQuickFramebufferObject
{
    Q_OBJECT
    Q_PROPERTY(Node* sceneData READ getSceneData WRITE setSceneData NOTIFY sceneDataChanged)
    Q_PROPERTY(Camera* camera READ getCamera WRITE setCamera NOTIFY cameraChanged)

public:
    Viewer();
    Renderer* createRenderer() const;
    Q_INVOKABLE void saveScene(QString path);

    Node* getSceneData() const { return sceneData; }
    void setSceneData(Node* sceneData);

    Camera* getCamera();
    void setCamera(Camera* camera);

signals:
    void sceneDataChanged(Node* sceneData);
    void cameraChanged(Camera* camera);

protected:
    QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData* nodeData) override;

    void wheelEvent(QWheelEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    osgGA::GUIEventAdapter::MouseButtonMask mouseButtonMask(QMouseEvent *event);
    osgViewer::Viewer* osgViewer;
    Node* sceneData;
    Camera* camera = nullptr;
};
