#include "text.h"

void Text::classBegin() {
    if (osgObj == nullptr) {
        osgObj = new osgText::Text;
    }
    TextBase::classBegin();
}
