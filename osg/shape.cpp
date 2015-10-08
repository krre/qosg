#include "shape.h"

Shape::Shape()
{

}

void Shape::classBegin()
{
    shape = static_cast<osg::Shape*>(obj);
    Object::classBegin();
}
