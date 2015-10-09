#pragma once
#include <osg/Shape>
#include "shape.h"
#include <QVector3D>

class Box : public Shape
{
    Q_OBJECT
    Q_PROPERTY(QVector3D halfLengths READ getHalfLengths WRITE setHalfLengths NOTIFY halfLengthsChanged)
public:
    Box() {}
    void classBegin() override;
    osg::Box* toOsg() { return static_cast<osg::Box*>(osgObj); }

    QVector3D getHalfLengths() const;
    void setHalfLengths(QVector3D halfLengths);
signals:
    void halfLengthsChanged(QVector3D halfLengths);
private:
    QVector3D halfLengths;
};
