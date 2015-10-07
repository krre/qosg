#pragma once
#include <QtCore>
#include <QtGui>
#include <QtQuick>
#include <osgViewer/Viewer>
#include <osg/Texture2D>
#include "viewer_thread.h"

// Based on Qt example "Scene Graph - Rendering FBOs in a thread"
class ViewerThread;

class RenderThread : public QThread
{
    Q_OBJECT
public:
    RenderThread(const QSize& size, osgViewer::Viewer* viewer, osg::Texture2D* fboTexture);
    QOpenGLContext* context = nullptr;
    QOffscreenSurface *surface;

public slots:
    void renderNext();
    void shutDown();

signals:
    void textureReady(int id, const QSize &size);

private:
    QOpenGLFramebufferObject* m_renderFbo = nullptr;

    osgViewer::Viewer* osgViewer;
    osg::Texture2D* fboTexture;
    QSize m_size;
    QQuickWindow* window;
};
