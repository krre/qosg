#pragma once
#include <osg/Node>
#include "object.h"

class Node : public Object
{
    Q_OBJECT
public:
    Node() {}
    void classBegin() override { osgObj = new osg::Node; }
    osg::Node* toOsg() { return static_cast<osg::Node*>(osgObj.get()); }
};

