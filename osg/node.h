#pragma once
#include <osg/Node>
#include "object.h"

class Node : public Object, public osg::Node
{
    Q_OBJECT

public:
    Node() {}
};
