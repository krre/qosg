#pragma once
#include <osg/Shape>
#include "shape.h"
#include "../converter.h"

class Cylinder : public Shape
{
    Q_OBJECT
    Q_PROPERTY(float radius READ getRadius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(float height READ getHeight WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(QVector3D center READ getCenter WRITE setCenter NOTIFY centerChanged)

public:
    Cylinder() {}
    void classBegin() override { osgObj = new osg::Cylinder; }
    osg::Cylinder* toOsg() { return static_cast<osg::Cylinder*>(osgObj.get()); }

    float getRadius() { return toOsg()->getRadius(); }
    void setRadius(float radius);

    float getHeight() { return toOsg()->getHeight(); }
    void setHeight(float height);

    QVector3D getCenter() { return Converter::fromVec3(toOsg()->getCenter()); }
    void setCenter(const QVector3D& center);

signals:
    void radiusChanged(float radius);
    void heightChanged(float height);
    void centerChanged(const QVector3D& center);
};

