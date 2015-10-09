#pragma once
#include <osg/ShapeDrawable>
#include "drawable.h"

class ShapeDrawable : public Drawable, public osg::ShapeDrawable
{
    Q_OBJECT

public:
    ShapeDrawable() {}
};
