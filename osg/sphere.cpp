#include "sphere.h"

void Sphere::setRadius(float radius)
{
    if (toOsg()->getRadius() == radius) return;
    toOsg()->setRadius(radius);
    emit radiusChanged(radius);
}

void Sphere::setCenter(const QVector3D& center)
{
    osg::Vec3 vec3 = Converter::toVec3(center);
    if (toOsg()->getCenter() == vec3) return;
    toOsg()->setCenter(vec3);
    emit centerChanged(center);
}
