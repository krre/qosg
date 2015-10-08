#include "shape.h"

Shape::Shape()
{

}

void Shape::classBegin()
{
    qDebug() << "classBegin Shape";
    shape = static_cast<osg::Shape*>(obj);
    Object::classBegin();
}
