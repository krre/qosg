#pragma once
#include <osgText/TextBase>
#include "../osg/drawable.h"
#include "../converter.h"

class TextBase : public Drawable {
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QColor color READ getColor WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(float characterSize READ getCharacterSize WRITE setCharacterSize NOTIFY characterSizeChanged)
    Q_PROPERTY(QVector3D position READ getPosition WRITE setPosition NOTIFY positionChanged)

public:
    void classBegin() override;
    osgText::TextBase* toOsg() { return static_cast<osgText::TextBase*>(osgObj.get()); }

    QString text() { return Converter::fromOsgString(toOsg()->getText()); }
    void setText(const QString& text);

    QColor getColor() { return Converter::fromVec4(toOsg()->getColor()); }
    void setColor(const QColor& color);

    float getCharacterSize() { return toOsg()->getCharacterHeight(); }
    void setCharacterSize(float characterSize);

    QVector3D getPosition() { return Converter::fromVec3(toOsg()->getPosition()); }
    void setPosition(const QVector3D& position);

signals:
    void textChanged(const QString& text);
    void colorChanged(const QColor& color);
    void characterSizeChanged(float characterSize);
    void positionChanged(const QVector3D& position);
};
