#pragma once
#include <osg/Shape>
#include "object.h"

class Shape : public Object
{
    Q_OBJECT
public:
    Shape() {}
    osg::Shape* toOsg() { return static_cast<osg::Shape*>(osgObj.get()); }
};
