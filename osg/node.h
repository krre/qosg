#pragma once
#include <osg/Node>
#include "object.h"

class Node : public Object
{
    Q_OBJECT
public:
    Node() {}
    void classBegin() override;
    osg::Node* toOsg() { return static_cast<osg::Node*>(osgObj.get()); }
    void fromOsg(osg::Node* node) { osgObj = node; }
};

