#include "transform.h"

Transform::Transform()
{

}

void Transform::classBegin()
{
    if (obj == nullptr) {
        obj = new osg::Transform;
    }
    transform = static_cast<osg::Transform*>(obj);
    Group::classBegin();
}
