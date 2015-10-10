#include "sphere.h"

void Sphere::setRadius(float radius)
{
    if (toOsg()->getRadius() == radius) return;
    toOsg()->setRadius(radius);
    emit radiusChanged(radius);
}
