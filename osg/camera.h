#pragma once
#include <osg/Camera>
#include "transform.h"

class Camera : public Transform
{
    Q_OBJECT

public:
    Camera() {}
    void classBegin() override;
    osg::Camera* toOsg() { return static_cast<osg::Camera*>(osgObj); }
    void fromOsg(osg::Camera* camera);
};
