#pragma once
#include <osg/Node>
#include "object.h"
#include "boundingsphere.h"

class Group;

class Node : public Object {
    Q_OBJECT
    Q_PROPERTY(BoundingSphere* bound READ getBound CONSTANT)

public:
    void classBegin() override;

    osg::Node* toOsg() { return static_cast<osg::Node*>(osgObj.get()); }
    void fromOsg(osg::Node* node) { osgObj = node; }

    BoundingSphere* getBound();

    Q_INVOKABLE Group* getParentGroup() { return parentGroup; }
    Q_INVOKABLE void setParentGroup(Group* parentGroup) { this->parentGroup = parentGroup; }
private:
    BoundingSphere bound;
    Group* parentGroup;
};

