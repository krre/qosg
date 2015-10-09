#pragma once
#include <osg/Group>
#include "node.h"

class Group : public Node, public osg::Group
{
    Q_OBJECT

public:
    Group() {}
};
