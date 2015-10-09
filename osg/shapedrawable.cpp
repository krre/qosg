#include "shapedrawable.h"
#include <QDebug>

void ShapeDrawable::setShape(Shape* shape)
{
    if (static_cast<Shape*>(getShape()) == shape) return;
    osg::ShapeDrawable::setShape(static_cast<osg::Shape*>(shape));
    setColor(osg::Vec4(1, 1, 0, 1));
//    qDebug() << shape;
    emit shapeChanged(shape);
}
