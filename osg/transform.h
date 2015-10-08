#pragma once
#include <QtCore>
#include "group.h"
#include <osg/Transform>

class Transform : public Group
{
    Q_OBJECT

public:
    Transform();
    void classBegin() override;

private:
    osg::Transform* transform;
};
