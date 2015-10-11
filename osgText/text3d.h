#pragma once
#include <osgText/Text3D>
#include "textbase.h"

class Text3D : public TextBase
{
    Q_OBJECT
    Q_PROPERTY(float characterDepth READ characterDepth WRITE setCharacterDepth NOTIFY characterDepthChanged)
    float m_characterDepth;

public:
    Text3D() {}
    void classBegin() override;
    osgText::Text3D* toOsg() { return static_cast<osgText::Text3D*>(osgObj.get()); }

    float characterDepth() { return toOsg()->getCharacterDepth(); }
    void setCharacterDepth(float characterDepth);
signals:
    void characterDepthChanged(float characterDepth);
};
