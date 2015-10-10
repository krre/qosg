#include "box.h"

void Box::setHalfLengths(const QVector3D& halfLengths)
{
    osg::Vec3 vec3 = Converter::toVec3(halfLengths);
    if (toOsg()->getHalfLengths() == vec3) return;
    toOsg()->setHalfLengths(vec3);
    emit halfLengthsChanged(halfLengths);
}
