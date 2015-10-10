#include "camera.h"
#include <osg/Vec4>

void Camera::setClearColor(const QColor& clearColor)
{
    osg::Vec4 vec4 = Converter::toVec4(clearColor);
    if (vec4 == toOsg()->getClearColor()) return;
    toOsg()->setClearColor(vec4);
    emit clearColorChanged(clearColor);
}
