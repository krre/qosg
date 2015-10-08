#include "drawable.h"

Drawable::Drawable()
{

}

void Drawable::classBegin()
{
    drawable = static_cast<osg::Drawable*>(obj);
    Object::classBegin();
}
