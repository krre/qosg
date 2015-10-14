#include "positionattitudetransform.h"

void PositionAttitudeTransform::classBegin()
{
    if (osgObj == nullptr) {
        osgObj = new osg::PositionAttitudeTransform;
    }
    Transform::classBegin();
}
