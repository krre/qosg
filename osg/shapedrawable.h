#pragma once
#include <QtCore>
#include "drawable.h"
#include <osg/ShapeDrawable>

class ShapeDrawable : public Drawable
{
    Q_OBJECT

public:
    ShapeDrawable();
    void classBegin() override;
    osg::ShapeDrawable* instance() { return shapeDrawable; }

private:
    osg::ShapeDrawable* shapeDrawable;
};
