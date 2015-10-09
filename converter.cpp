#include "converter.h"




osg::Vec4 Converter::qColorToVec4(QColor color)
{
    return osg::Vec4(color.redF(), color.greenF(), color.blueF(), color.alphaF());
}

QColor Converter::vec4ToQColor(osg::Vec4 vec4)
{
    return QColor::fromRgbF(vec4.r(), vec4.g(), vec4.b(), vec4.a());
}
