#pragma once
#include <osg/Geode>
#include <osg/Drawable>
#include <QtQml>
#include "drawable.h"
#include "node.h"

class Geode : public Node
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Drawable> drawableList READ drawableList NOTIFY drawableListChanged)
    Q_CLASSINFO("DefaultProperty", "drawableList")

public:
    Geode() {}
    void classBegin() override;
    osg::Geode* toOsg() { return static_cast<osg::Geode*>(osgObj); }
    QQmlListProperty<Drawable> drawableList() { return QQmlListProperty<Drawable>(this, 0, Geode::append, Geode::count, Geode::at, Geode::clear); }

signals:
    void drawableListChanged();

private:
    static void append(QQmlListProperty<Drawable>* list, Drawable* drawable);
    static Drawable* at(QQmlListProperty<Drawable>* list, int index);
    static int count(QQmlListProperty<Drawable>* list);
    static void clear(QQmlListProperty<Drawable>* list);
    QList<Drawable*> drawables;
};
