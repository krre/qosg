#include "group.h"

Group::Group()
{

}

void Group::classBegin()
{
    qDebug() << "classBegin Group";
    if (obj == nullptr) {
        obj = new osg::Group;
    }
    group = static_cast<osg::Group*>(obj);
    Node::classBegin();
}

