#include "camera.h"
#include "../converter.h"
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
    return Converter::vec4ToQColor(toOsg()->getClearColor());
}

void Camera::setClearColor(QColor clearColor)
{
    osg::Vec4 vec4 = Converter::qColorToVec4(clearColor);
    if (vec4 == toOsg()->getClearColor()) return;
    toOsg()->setClearColor(vec4);
    emit clearColorChanged(clearColor);
}
