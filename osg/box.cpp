#include "box.h"

Box::Box()
{

}

void Box::classBegin()
{
    qDebug() << "classBegin Box";
    if (obj == nullptr) {
        obj = new osg::Box;
    }
    box = static_cast<osg::Box*>(obj);
    Shape::classBegin();
}
