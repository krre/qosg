#include "shapedrawable.h"
#include <QDebug>

void ShapeDrawable::classBegin()
{
    if (osgObj == nullptr) {
        osgObj = new osg::ShapeDrawable;
    }
    Drawable::classBegin();
}

void ShapeDrawable::setShape(Shape* shape)
{
    if (this->shape == shape) return;
    this->shape = shape;
    toOsg()->setShape(shape->toOsg());
    toOsg()->setColor(osg::Vec4(1.0, 1.0, 0, 1.0));
    emit shapeChanged(shape);
}
