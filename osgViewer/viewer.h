#pragma once
#include <QtQuick/QQuickFramebufferObject>

class ViewerRenderer : public QQuickFramebufferObject::Renderer
{
public:
    ViewerRenderer() {}
    void render();
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size);
};

class Viewer : public QQuickFramebufferObject
{
    Q_OBJECT

public:
    Renderer* createRenderer() const;
};
