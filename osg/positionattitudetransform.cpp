#include "positionattitudetransform.h"

void PositionAttitudeTransform::classBegin()
{
    if (osgObj == nullptr) {
        osgObj = new osg::PositionAttitudeTransform;
    }
    Transform::classBegin();
}

void PositionAttitudeTransform::setPosition(const QVector3D& position)
{
    osg::Vec3 vec3 = Converter::toVec3(position);
    if (toOsg()->getPosition() == vec3) return;
    toOsg()->setPosition(vec3);
    emit positionChanged(position);
}
