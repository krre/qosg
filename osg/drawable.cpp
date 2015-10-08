#include "drawable.h"

Drawable::Drawable()
{

}

void Drawable::classBegin()
{
    qDebug() << "classBegin Drawable";
    drawable = static_cast<osg::Drawable*>(obj);
    Object::classBegin();
}
