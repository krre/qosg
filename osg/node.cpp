#include "node.h"

Node::Node()
{

}

void Node::classBegin()
{
    if (obj == nullptr) {
        obj = new osg::Node;
    }
    node = static_cast<osg::Node*>(obj);
    Object::classBegin();
}
