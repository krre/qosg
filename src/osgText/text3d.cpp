#include "text3d.h"

void Text3D::classBegin() {
    if (osgObj == nullptr) {
        osgObj = new osgText::Text3D;
    }
    TextBase::classBegin();
}

void Text3D::setCharacterDepth(float characterDepth) {
    if (toOsg()->getCharacterDepth() == characterDepth) return;
    toOsg()->setCharacterDepth(characterDepth);
    emit characterDepthChanged(characterDepth);
}
