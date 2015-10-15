#include "shapedrawable.h"

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
    emit shapeChanged(shape);
}

void ShapeDrawable::setColor(const QColor &color)
{
    osg::Vec4 vec4 = Converter::toVec4(color);
    if (vec4 == toOsg()->getColor()) return;
    toOsg()->setColor(vec4);
    emit colorChanged(color);
}
