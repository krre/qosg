#pragma once
#include <osg/PositionAttitudeTransform>
#include "transform.h"

class PositionAttitudeTransform : public Transform
{
    Q_OBJECT
public:
    PositionAttitudeTransform() {}
    void classBegin() override;
    osg::PositionAttitudeTransform* toOsg() { return static_cast<osg::PositionAttitudeTransform*>(osgObj.get()); }
};
