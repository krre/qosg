#pragma once
#include <osg/Shape>
#include "shape.h"
#include <QVector3D>
#include "../converter.h"

class Box : public Shape
{
    Q_OBJECT
    Q_PROPERTY(QVector3D halfLengths READ getHalfLengths WRITE setHalfLengths NOTIFY halfLengthsChanged)
public:
    Box() {}
    void classBegin() override { osgObj = new osg::Box; }
    osg::Box* toOsg() { return static_cast<osg::Box*>(osgObj); }

    QVector3D getHalfLengths() { return Converter::fromVec3(toOsg()->getHalfLengths()); }
    void setHalfLengths(const QVector3D& halfLengths);
signals:
    void halfLengthsChanged(const QVector3D& halfLengths);
};
