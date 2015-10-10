#include "textbase.h"
#include <osgText/Font>

void TextBase::classBegin()
{
    toOsg()->setAxisAlignment(osgText::TextBase::AxisAlignment::XZ_PLANE);
    toOsg()->setCharacterSize(0.15);
    toOsg()->setFont("fonts/times.ttf");
}

void TextBase::setText(const QString& text)
{
    if (toOsg()->getText().createUTF8EncodedString() == text.toStdString()) return;
    toOsg()->setText(text.toStdString());
    emit textChanged(text);
}

void TextBase::setColor(const QColor &color)
{
    osg::Vec4 vec4 = Converter::toVec4(color);
    if (vec4 == toOsg()->getColor()) return;
    toOsg()->setColor(vec4);
    emit colorChanged(color);
}
