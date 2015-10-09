#include "text3d.h"

void Text3D::classBegin()
{
    if (osgObj == nullptr) {
        osgObj = new osgText::Text3D;
    }
    TextBase::classBegin();
}
