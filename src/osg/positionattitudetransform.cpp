#include "positionattitudetransform.h"

void PositionAttitudeTransform::classBegin() {
    if (osgObj == nullptr) {
        osgObj = new osg::PositionAttitudeTransform;
    }
    Transform::classBegin();
}

void PositionAttitudeTransform::setPosition(const QVector3D& position) {
    osg::Vec3 vec3 = Converter::toVec3(position);
    if (toOsg()->getPosition() == vec3) return;
    toOsg()->setPosition(vec3);
    emit positionChanged(position);
}

void PositionAttitudeTransform::setAttitude(const QQuaternion& attitude) {
    osg::Quat quat = Converter::toQuat(attitude);
    if (toOsg()->getAttitude() == quat) return;
    toOsg()->setAttitude(quat);
    emit attitudeChanged(attitude);
}

void PositionAttitudeTransform::setScale(const QVector3D& scale) {
    osg::Vec3 vec3 = Converter::toVec3(scale);
    if (toOsg()->getScale() == vec3) return;
    toOsg()->setScale(vec3);
    emit scaleChanged(scale);
}

void PositionAttitudeTransform::setPivotPoint(const QVector3D& pivotPoint) {
    osg::Vec3 vec3 = Converter::toVec3(pivotPoint);
    if (toOsg()->getPivotPoint() == vec3) return;
    toOsg()->setPivotPoint(vec3);
    emit pivotPointChanged(pivotPoint);
}
