#pragma once
#include <osg/PositionAttitudeTransform>
#include "transform.h"
#include "../converter.h"

class PositionAttitudeTransform : public Transform
{
    Q_OBJECT
    Q_PROPERTY(QVector3D position READ getPosition WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QQuaternion attitude READ getAttitude WRITE setAttitude NOTIFY attitudeChanged)
    Q_PROPERTY(QVector3D scale READ getScale WRITE setScale NOTIFY scaleChanged)
public:
    PositionAttitudeTransform() {}
    void classBegin() override;
    osg::PositionAttitudeTransform* toOsg() { return static_cast<osg::PositionAttitudeTransform*>(osgObj.get()); }

    QVector3D getPosition() { return Converter::fromVec3(toOsg()->getPosition()); }
    void setPosition(const QVector3D& position);

    QQuaternion getAttitude() { return Converter::fromQuat(toOsg()->getAttitude()); }
    void setAttitude(const QQuaternion &attitude);

    QVector3D getScale() { return Converter::fromVec3(toOsg()->getScale()); }
    void setScale(const QVector3D& scale);

signals:
    void positionChanged(const QVector3D& position);
    void attitudeChanged(const QQuaternion& attitude);
    void scaleChanged(const QVector3D& scale);
};
