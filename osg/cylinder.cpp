#include "cylinder.h"

void Cylinder::setRadius(float radius)
{
    if (toOsg()->getRadius() == radius) return;
    toOsg()->setRadius(radius);
    emit radiusChanged(radius);
}

void Cylinder::setHeight(float height)
{
    if (toOsg()->getHeight() == height) return;
    toOsg()->setHeight(height);
    emit heightChanged(height);
}
