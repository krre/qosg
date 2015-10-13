#include "node.h"

void Node::classBegin()
{
    osgObj = new osg::Node;
    Object::classBegin();
}
