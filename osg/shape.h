#pragma once
#include <osg/Shape>
#include "object.h"

class Shape : public Object, public osg::Shape
{
    Q_OBJECT
public:
    Shape() {}
    osg::Object* cloneType() const { return nullptr; }
    osg::Object* clone(const osg::CopyOp&) const { return nullptr; }
    void accept(osg::ShapeVisitor&) {}
    void accept(osg::ConstShapeVisitor&) const {}
};

