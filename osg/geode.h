#pragma once
#include <QtCore>
#include <osg/Geode>
#include "node.h"
#include "drawable.h"



class Geode : public Node
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Drawable> drawableList READ drawableList NOTIFY drawableListChanged)
    Q_CLASSINFO("DefaultProperty", "drawableList")

public:
    Geode();
    void classBegin() override;
    osg::Geode* instance() { return geode; }

    QQmlListProperty<Drawable> drawableList() { return QQmlListProperty<Drawable>(this, 0, Geode::append, Geode::count, Geode::at, Geode::clear); }

signals:
    void drawableListChanged();

private:
    osg::Geode* geode;

    static void append(QQmlListProperty<Drawable>* list, Drawable* drawable);
    static Drawable* at(QQmlListProperty<Drawable>* list, int index);
    static int count(QQmlListProperty<Drawable>* list);
    static void clear(QQmlListProperty<Drawable>* list);
//    QQmlListProperty<Drawable> m_drawableList;
};
