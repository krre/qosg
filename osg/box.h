#pragma once
#include <osg/Shape>
#include "shape.h"
#include <QVector3D>
#include "../converter.h"

class Box : public Shape
{
    Q_OBJECT
    Q_PROPERTY(QVector3D halfLengths READ getHalfLengths WRITE setHalfLengths NOTIFY halfLengthsChanged)
    Q_PROPERTY(QVector3D center READ getCenter WRITE setCenter NOTIFY centerChanged)
public:
    Box() {}
    void classBegin() override { osgObj = new osg::Box; }
    osg::Box* toOsg() { return static_cast<osg::Box*>(osgObj.get()); }

    QVector3D getHalfLengths() { return Converter::fromVec3(toOsg()->getHalfLengths()); }
    void setHalfLengths(const QVector3D& halfLengths);

    QVector3D getCenter() { return Converter::fromVec3(toOsg()->getCenter()); }
    void setCenter(const QVector3D& center);

signals:
    void halfLengthsChanged(const QVector3D& halfLengths);
    void centerChanged(const QVector3D& center);
};
