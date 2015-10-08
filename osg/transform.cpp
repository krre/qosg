#include "transform.h"

Transform::Transform()
{

}

void Transform::classBegin()
{
    qDebug() << "classBegin Transform";
    if (obj == nullptr) {
        obj = new osg::Transform;
    }
    transform = static_cast<osg::Transform*>(obj);
    Group::classBegin();
}
