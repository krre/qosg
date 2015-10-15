#pragma once
#include <osg/Node>
#include "object.h"
#include "boundingsphere.h"

class Node : public Object
{
    Q_OBJECT
    Q_PROPERTY(BoundingSphere* bound READ getBound CONSTANT)

public:
    void classBegin() override;

    osg::Node* toOsg() { return static_cast<osg::Node*>(osgObj.get()); }
    void fromOsg(osg::Node* node) { osgObj = node; }

    BoundingSphere* getBound();
private:
    BoundingSphere bound;
};

