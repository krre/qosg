#pragma once
#include <QtCore>
#include <QQuickItem>
#include <osgViewer/View>
#include <osg/Camera>
#include <osg/GraphicsContext>
#include <osgViewer/CompositeViewer>

class View : public QQuickItem
{
    Q_OBJECT
public:
    explicit View();
private:
    osg::ref_ptr<osgViewer::View> view;
    osg::Camera* camera;
    osg::GraphicsContext* graphicsContext;
    void geometryChanged(const QRectF& newGeometry, const QRectF& oldGeometry) override;
    QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*) override;
    void timerEvent(QTimerEvent*) override;
    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> graphicsWindowEmbedded;
    osg::ref_ptr<osgViewer::CompositeViewer> compositeViewer;
};
