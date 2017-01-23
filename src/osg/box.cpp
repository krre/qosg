#include "box.h"

void Box::classBegin() {
    if (osgObj == nullptr) {
        osgObj = new osg::Box;
    }
    Shape::classBegin();
}

void Box::setHalfLengths(const QVector3D& halfLengths) {
    osg::Vec3 vec3 = Converter::toVec3(halfLengths);
    if (toOsg()->getHalfLengths() == vec3) return;
    toOsg()->setHalfLengths(vec3);
    emit halfLengthsChanged(halfLengths);
}

void Box::setCenter(const QVector3D& center) {
    osg::Vec3 vec3 = Converter::toVec3(center);
    if (toOsg()->getCenter() == vec3) return;
    toOsg()->setCenter(vec3);
    emit centerChanged(center);
}
