#include "Transform.h"

void Transform::classBegin() {
    if (osgObj == nullptr) {
        osgObj = new osg::Transform;
    }
    Group::classBegin();
}
