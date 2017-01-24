#pragma once
#include <osg/Shape>
#include "Object.h"

class Shape : public Object {
    Q_OBJECT
public:
    void classBegin() override;
    osg::Shape* toOsg() { return static_cast<osg::Shape*>(osgObj.get()); }
};
