#include "text3d.h"

void Text3D::classBegin()
{
    osgObj = new osgText::Text3D;
    TextBase::classBegin();
}
