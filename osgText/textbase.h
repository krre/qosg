#pragma once
#include <osgText/TextBase>
#include "../osg/drawable.h"

class TextBase : Drawable
{
public:
    TextBase();
    void classBegin() override;
    osgText::TextBase* toOsg() { return static_cast<osgText::TextBase*>(osgObj); }
};
