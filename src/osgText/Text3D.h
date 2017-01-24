#pragma once
#include <osgText/Text3D>
#include "TextBase.h"

class Text3D : public TextBase {
    Q_OBJECT
    Q_PROPERTY(float characterDepth READ getCharacterDepth WRITE setCharacterDepth NOTIFY characterDepthChanged)

public:
    void classBegin() override;
    osgText::Text3D* toOsg() { return static_cast<osgText::Text3D*>(osgObj.get()); }

    float getCharacterDepth() { return toOsg()->getCharacterDepth(); }
    void setCharacterDepth(float characterDepth);
signals:
    void characterDepthChanged(float characterDepth);
};
