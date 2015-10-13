#include "transform.h"

void Transform::classBegin()
{
    osgObj = new osg::Transform;
    Group::classBegin();
}
