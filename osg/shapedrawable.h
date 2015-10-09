#pragma once
#include <osg/ShapeDrawable>
#include "drawable.h"
#include "shape.h"

class ShapeDrawable : public Drawable, public osg::ShapeDrawable
{
    Q_OBJECT
    Q_PROPERTY(Shape* shape READ getShape WRITE setShape NOTIFY shapeChanged)
public:
    ShapeDrawable() {}

    Shape* getShape() { return static_cast<Shape*>(osg::ShapeDrawable::getShape()); }
    void setShape(Shape* shape);
signals:
    void shapeChanged(Shape* shape);
};
