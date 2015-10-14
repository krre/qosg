#pragma once
#include <osg/PositionAttitudeTransform>
#include "transform.h"
#include "../converter.h"

class PositionAttitudeTransform : public Transform
{
    Q_OBJECT
    Q_PROPERTY(QVector3D position READ getPosition WRITE setPosition NOTIFY positionChanged)
public:
    PositionAttitudeTransform() {}
    void classBegin() override;
    osg::PositionAttitudeTransform* toOsg() { return static_cast<osg::PositionAttitudeTransform*>(osgObj.get()); }

    QVector3D getPosition() { return Converter::fromVec3(toOsg()->getPosition()); }
    void setPosition(const QVector3D& position);

signals:
    void positionChanged(const QVector3D& position);
};
