#include "shapedrawable.h"

ShapeDrawable::ShapeDrawable()
{

}

void ShapeDrawable::classBegin()
{
    if (obj == nullptr) {
        obj = new osg::ShapeDrawable;
    }
    shapeDrawable = static_cast<osg::ShapeDrawable*>(obj);
    Drawable::classBegin();
}
