#pragma once
#include <osg/Camera>
#include <QColor>
#include "transform.h"
#include "../converter.h"

class Camera : public Transform
{
    Q_OBJECT
    Q_PROPERTY(QColor clearColor READ getClearColor WRITE setClearColor NOTIFY clearColorChanged)

public:
    Camera() {}
    void classBegin() override { osgObj = new osg::Camera; }

    osg::Camera* toOsg() { return static_cast<osg::Camera*>(osgObj.get()); }
    void fromOsg(osg::Camera* camera) { osgObj = camera; }

    QColor getClearColor() { return Converter::fromVec4(toOsg()->getClearColor()); }
    void setClearColor(const QColor& clearColor);
signals:
    void clearColorChanged(const QColor& clearColor);
};
