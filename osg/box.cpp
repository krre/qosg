#include "box.h"

Box::Box()
{

}

void Box::classBegin()
{
    if (obj == nullptr) {
        obj = new osg::Box;
    }
    box = static_cast<osg::Box*>(obj);
    Shape::classBegin();
}
