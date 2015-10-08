#pragma once
#include <osg/Geode>
#include <osg/Drawable>
#include <QtQml>
#include "node.h"

class Geode : public Node, public osg::Geode
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<osg::Drawable> drawableList READ drawableList NOTIFY drawableListChanged)
    Q_CLASSINFO("DefaultProperty", "drawableList")

public:
    Geode() {}
    QQmlListProperty<osg::Drawable> drawableList() { return QQmlListProperty<osg::Drawable>(this, 0, Geode::append, Geode::count, Geode::at, Geode::clear); }

signals:
    void drawableListChanged();

private:
    static void append(QQmlListProperty<osg::Drawable>* list, osg::Drawable* drawable);
    static osg::Drawable* at(QQmlListProperty<osg::Drawable>* list, int index);
    static int count(QQmlListProperty<osg::Drawable>* list);
    static void clear(QQmlListProperty<osg::Drawable>* list);
};
