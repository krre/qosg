#pragma once
#include <osg/Shape>
#include "shape.h"

class Sphere : public Shape, public osg::Sphere
{
    Q_OBJECT
    Q_PROPERTY(float radius READ getRadius WRITE setRadius NOTIFY radiusChanged)

public:
    Sphere() {}

    void setRadius(float radius);

signals:
    void radiusChanged(float radius);
};
