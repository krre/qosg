#include "sphere.h"

void Sphere::classBegin()
{
    if (osgObj == nullptr) {
        osgObj = new osg::Sphere;
    }
    Shape::classBegin();
}

void Sphere::setRadius(float radius)
{
    if (toOsg()->getRadius() == radius) return;
    toOsg()->setRadius(radius);
    emit radiusChanged(radius);
}

