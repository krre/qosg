#include "node.h"

Node::Node()
{

}

void Node::classBegin()
{
    qDebug() << "classBegin Node";
    if (obj == nullptr) {
        obj = new osg::Node;
    }
    node = static_cast<osg::Node*>(obj);
    Object::classBegin();
}
