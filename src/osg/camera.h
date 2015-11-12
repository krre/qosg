#pragma once
#include <osg/Camera>
#include <QColor>
#include <QMap>
#include "transform.h"
#include "../converter.h"

class Camera : public Transform
{
    Q_OBJECT
    Q_PROPERTY(QColor clearColor READ getClearColor WRITE setClearColor NOTIFY clearColorChanged)
    Q_PROPERTY(double fovy READ getFovy WRITE setFovy NOTIFY fovyChanged)
    Q_PROPERTY(double aspectRatio READ getAspectRatio WRITE setAspectRatio NOTIFY aspectRatioChanged)
    Q_PROPERTY(double zNear READ getZNear WRITE setZNear NOTIFY zNearChanged)
    Q_PROPERTY(double zFar READ getZFar WRITE setZFar NOTIFY zFarChanged)

public:
    void classBegin() override;

    osg::Camera* toOsg() { return static_cast<osg::Camera*>(osgObj.get()); }
    void fromOsg(osg::Camera* camera) { osgObj = camera; }

    QColor getClearColor() { return Converter::fromVec4(toOsg()->getClearColor()); }
    void setClearColor(const QColor& clearColor);

    double getFovy();
    void setFovy(double fovy);

    double getAspectRatio();
    void setAspectRatio(double aspectRatio);

    double getZNear();
    void setZNear(double zNear);

    double getZFar();
    void setZFar(double zFar);

signals:
    void clearColorChanged(const QColor& clearColor);
    void fovyChanged(double fovy);
    void aspectRatioChanged(double aspectRatio);
    void zNearChanged(double zNear);
    void zFarChanged(double zFar);

private:
    QMap<QString, double> getLens();
    void setLens(const QMap<QString, double> &lens);
};
