#pragma once
#include <osg/Transform>
#include "group.h"

class Transform : public Group, public osg::Transform
{
    Q_OBJECT
public:
    Transform() {}
};
