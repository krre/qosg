#include "camera.h"

void Camera::classBegin()
{
    if (osgObj == nullptr) {
        osgObj = new osg::Camera;
    }
    Transform::classBegin();
}
