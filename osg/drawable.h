#pragma once
#include <osg/Drawable>
#include "object.h"

class Drawable : public Object, public osg::Drawable
{
    Q_OBJECT
public:
    Drawable() {}
    void drawImplementation(osg::RenderInfo&) const {}
    osg::Object* cloneType() const { return nullptr; }
    osg::Object* clone(const osg::CopyOp&) const { return nullptr; }
};

