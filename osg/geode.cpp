#include "geode.h"

void Geode::append(QQmlListProperty<Drawable>* list, Drawable* drawable)
{
    if (!drawable) return;
    Geode* self = static_cast<Geode*>(list->object);
    self->addDrawable(static_cast<osg::Drawable*>(drawable));
    self->drawableListChanged();
}

Drawable* Geode::at(QQmlListProperty<Drawable>* list, int index)
{
    return static_cast<Drawable*>(static_cast<Geode*>(list->object)->getDrawable(index));
}

int Geode::count(QQmlListProperty<Drawable>* list)
{
    return static_cast<Geode*>(list->object)->getNumDrawables();
}

void Geode::clear(QQmlListProperty<Drawable>* list)
{
    Geode* self = static_cast<Geode*>(list->object);
    self->removeDrawables(0, self->getNumDrawables());
    self->drawableListChanged();
}
