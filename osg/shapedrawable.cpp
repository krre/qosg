#include "shapedrawable.h"
#include <QDebug>

void ShapeDrawable::setShape(Shape* shape)
{
    if (this->shape == shape) return;
    this->shape = shape;
    toOsg()->setShape(shape->toOsg());
    emit shapeChanged(shape);
}
