#pragma once
#include <osgText/Text>
#include "textbase.h"

class Text : public TextBase
{
    Q_OBJECT
public:
    Text() {}
    void classBegin() override;
    osgText::Text* toOsg() { return static_cast<osgText::Text*>(osgObj); }
};

