#include "Cylinder.h"

void Cylinder::classBegin() {
    if (osgObj == nullptr) {
        osgObj = new osg::Cylinder;
    }
    Shape::classBegin();
}

void Cylinder::setRadius(float radius) {
    if (toOsg()->getRadius() == radius) return;
    toOsg()->setRadius(radius);
    emit radiusChanged(radius);
}

void Cylinder::setHeight(float height) {
    if (toOsg()->getHeight() == height) return;
    toOsg()->setHeight(height);
    emit heightChanged(height);
}

void Cylinder::setCenter(const QVector3D& center) {
    osg::Vec3 vec3 = Converter::toVec3(center);
    if (toOsg()->getCenter() == vec3) return;
    toOsg()->setCenter(vec3);
    emit centerChanged(center);
}
