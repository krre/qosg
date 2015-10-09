#pragma once
#include <osgText/TextBase>
#include "../osg/drawable.h"

class TextBase : public Drawable
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
public:
    TextBase() {}
    void classBegin() override;
    osgText::TextBase* toOsg() { return static_cast<osgText::TextBase*>(osgObj); }

    QString text() { return QString::fromStdString((toOsg()->getText().createUTF8EncodedString())); }
    void setText(QString text);
signals:
    void textChanged(QString text);
};
