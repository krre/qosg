#pragma once
#include <osgText/TextBase>
#include "../osg/drawable.h"
#include "../converter.h"

class TextBase : public Drawable
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
public:
    TextBase() {}
    void classBegin() override;
    osgText::TextBase* toOsg() { return static_cast<osgText::TextBase*>(osgObj); }

    QString text() { return Converter::fromOsgString(toOsg()->getText()); }
    void setText(const QString& text);
signals:
    void textChanged(QString text);
};
