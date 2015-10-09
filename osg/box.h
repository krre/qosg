#pragma once
#include <osg/Shape>
#include "shape.h"
#include <QVector3D>

class Box : public Shape, public osg::Box
{
    Q_OBJECT
    Q_PROPERTY(QVector3D halfLengths READ getHalfLengths WRITE setHalfLengths NOTIFY halfLengthsChanged)
public:
    Box() {}
    QVector3D getHalfLengths() const;
    void setHalfLengths(QVector3D halfLengths);
signals:
    void halfLengthsChanged(QVector3D halfLengths);
};
