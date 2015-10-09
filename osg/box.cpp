#include "box.h"

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
    osg::Vec3 osgVec3 = osg::Vec3(static_cast<osg::Vec3::value_type>(halfLengths.x()), static_cast<osg::Vec3::value_type>(halfLengths.y()), static_cast<osg::Vec3::value_type>(halfLengths.z()));
    toOsg()->setHalfLengths(osgVec3);
    emit halfLengthsChanged(halfLengths);
}
