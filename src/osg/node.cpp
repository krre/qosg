#include "node.h"

void Node::classBegin() {
    if (osgObj == nullptr) {
        osgObj = new osg::Node;
    }
    Object::classBegin();
}

BoundingSphere *Node::getBound() {
    bound.setBound(toOsg()->computeBound());
    return &bound;
}
