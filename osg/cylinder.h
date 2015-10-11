#pragma once
#include <osg/Shape>
#include "shape.h"

class Cylinder : public Shape
{
    Q_OBJECT
    Q_PROPERTY(float radius READ getRadius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(float height READ getHeight WRITE setHeight NOTIFY heightChanged)

public:
    Cylinder() {}
    void classBegin() override { osgObj = new osg::Cylinder; }
    osg::Cylinder* toOsg() { return static_cast<osg::Cylinder*>(osgObj.get()); }

    float getRadius() { return toOsg()->getRadius(); }
    void setRadius(float radius);

    float getHeight() { return toOsg()->getHeight(); }
    void setHeight(float height);

signals:
    void radiusChanged(float radius);
    void heightChanged(float height);
};

