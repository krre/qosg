#pragma once
#include <osg/Group>
#include "node.h"

class Group : public Node
{
    Q_OBJECT

public:
    Group() {}
    void classBegin() override;
    osg::Group* toOsg() { return static_cast<osg::Group*>(osgObj); }
};
