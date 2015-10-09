#pragma once
#include <osg/ShapeDrawable>
#include "drawable.h"
#include "shape.h"

class ShapeDrawable : public Drawable
{
    Q_OBJECT
    Q_PROPERTY(Shape* shape READ getShape WRITE setShape NOTIFY shapeChanged)
public:
    ShapeDrawable() {}
    void classBegin() override;
    osg::ShapeDrawable* toOsg() { return static_cast<osg::ShapeDrawable*>(osgObj); }

    Shape* getShape() { return shape; }
    void setShape(Shape* shape);
signals:
    void shapeChanged(Shape* shape);
private:
    Shape* shape;
};
