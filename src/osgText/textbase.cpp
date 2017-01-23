#include "textbase.h"
#include <osgText/Font>

void TextBase::classBegin() {
    toOsg()->setAxisAlignment(osgText::TextBase::AxisAlignment::XZ_PLANE);
    toOsg()->setFont("fonts/times.ttf");
    Drawable::classBegin();
}

void TextBase::setText(const QString& text) {
    if (toOsg()->getText().createUTF8EncodedString() == text.toStdString()) return;
    toOsg()->setText(text.toStdString());
    emit textChanged(text);
}

void TextBase::setColor(const QColor& color) {
    osg::Vec4 vec4 = Converter::toVec4(color);
    if (vec4 == toOsg()->getColor()) return;
    toOsg()->setColor(vec4);
    emit colorChanged(color);
}

void TextBase::setCharacterSize(float characterSize) {
    if (toOsg()->getCharacterHeight() == characterSize) return;
    toOsg()->setCharacterSize(characterSize);
    emit characterSizeChanged(characterSize);
}

void TextBase::setPosition(const QVector3D& position) {
    osg::Vec3 vec3 = Converter::toVec3(position);
    if (toOsg()->getPosition() == vec3) return;
    toOsg()->setPosition(vec3);
    emit positionChanged(position);
}
