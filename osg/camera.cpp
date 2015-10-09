#include "camera.h"

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
