#pragma once
#include "renderthread.h"
#include <QtCore>
#include <QtQuick>
#include <osgViewer/Viewer>
#include <osg/Vec4>
#include <osg/Texture2D>

class RenderThread;

class Viewer : public QQuickItem
{
    Q_OBJECT

public:
    Viewer();
    static QList<QThread*> threads;

public Q_SLOTS:
    void ready();

protected:
    QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*);
private:
    RenderThread* m_renderThread = nullptr;
    osg::ref_ptr<osgViewer::Viewer> viewer = nullptr;
    osg::ref_ptr<osg::Texture2D> fboTexture;
    qreal fov = 45.0;
    qreal zNear = 0.1;
    qreal zFar = 100.0;
    qreal zNearFarRatio = 0.01;
    osg::Vec4 color = osg::Vec4( 0.5f, 0.5f, 0.5f, 1.0f );
    friend class RenderThread;
};
