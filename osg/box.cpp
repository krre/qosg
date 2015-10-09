#include "box.h"
#include "../converter.h"

void Box::classBegin()
{
    if (osgObj == nullptr) {
        osgObj = new osg::Box;
    }
    Shape::classBegin();
}

QVector3D Box::getHalfLengths() const {
    return halfLengths;
}

void Box::setHalfLengths(QVector3D halfLengths)
{
    if (this->halfLengths == halfLengths) return;
    osg::Vec3 vec3 = Converter::toVec3(halfLengths);
    toOsg()->setHalfLengths(vec3);
    emit halfLengthsChanged(halfLengths);
}
