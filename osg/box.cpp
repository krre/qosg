#include "box.h"

QVector3D Box::getHalfLengths() const {
    osg::Vec3 osgVec3 = osg::Box::getHalfLengths();
    return QVector3D(static_cast<float>(osgVec3.x()), static_cast<float>(osgVec3.y()), static_cast<float>(osgVec3.z()));
}

void Box::setHalfLengths(QVector3D halfLengths)
{
    osg::Vec3 osgVec3 = osg::Vec3(static_cast<osg::Vec3::value_type>(halfLengths.x()), static_cast<osg::Vec3::value_type>(halfLengths.y()), static_cast<osg::Vec3::value_type>(halfLengths.z()));
    if (osgVec3 == osg::Box::getHalfLengths()) return;
    osg::Box::setHalfLengths(osgVec3);
    emit halfLengthsChanged(halfLengths);
}
