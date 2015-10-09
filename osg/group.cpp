#include "group.h"

void Group::classBegin()
{
    if (osgObj == nullptr) {
        osgObj = new osg::Group;
    }
    Node::classBegin();
}

