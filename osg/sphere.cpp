#include "sphere.h"

Sphere::Sphere()
{

}

void Sphere::setRadius(float radius)
{
    if (getRadius() == radius) return;
    osg::Sphere::setRadius(radius);
    emit radiusChanged(radius);
}

