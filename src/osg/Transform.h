#pragma once
#include <osg/Transform>
#include "Group.h"

class Transform : public Group {
    Q_OBJECT
public:
    void classBegin() override;
    osg::Transform* toOsg() { return static_cast<osg::Transform*>(osgObj.get()); }
};
