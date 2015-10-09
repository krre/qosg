#pragma once
#include <osg/Shape>
#include "shape.h"

class Box : public Shape, public osg::Box
{
    Q_OBJECT
public:
    Box() {}
};
