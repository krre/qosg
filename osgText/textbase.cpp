#include "textbase.h"

void TextBase::classBegin()
{
    Drawable::classBegin();
    toOsg()->setAxisAlignment(osgText::TextBase::AxisAlignment::XZ_PLANE);
}

void TextBase::setText(QString text)
{
    if (toOsg()->getText().createUTF8EncodedString() == text.toStdString()) return;

    toOsg()->setText(text.toStdString());
    emit textChanged(text);
}
