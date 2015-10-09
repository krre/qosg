#pragma once
#include <QColor>
#include <osg/Vec4>

class Converter
{
public:
    Converter() {}
    static osg::Vec4 qColorToVec4(QColor color);
    static QColor vec4ToQColor(osg::Vec4 vec4);
};

