#include "camera.h"
#include <osg/Vec4>

void Camera::classBegin()
{
    if (osgObj == nullptr) {
        osgObj = new osg::Camera;
    }
    Transform::classBegin();
}

void Camera::fromOsg(osg::Camera *camera)
{
    osgObj = camera;
}

QColor Camera::getClearColor()
{
    osg::Vec4 vec4 = toOsg()->getClearColor();
    return QColor::fromRgbF(vec4.r(), vec4.g(), vec4.b(), vec4.a());
}

void Camera::setClearColor(QColor clearColor)
{
    osg::Vec4 vec4 = osg::Vec4(clearColor.redF(), clearColor.greenF(), clearColor.blueF(), clearColor.alphaF());
    if (vec4 == toOsg()->getClearColor()) return;
    toOsg()->setClearColor(vec4);
    emit clearColorChanged(clearColor);
}
