#include "geode.h"

void Geode::append(QQmlListProperty<Drawable>* list, Drawable* drawable)
{
    if (!drawable) return;
    Geode* self = static_cast<Geode*>(list->object);
    self->drawables.append(drawable);
    self->toOsg()->addDrawable(drawable->toOsg());
    self->drawableListChanged();
}

Drawable* Geode::at(QQmlListProperty<Drawable>* list, int index)
{
    return static_cast<Geode*>(list->object)->drawables.at(index);
}

int Geode::count(QQmlListProperty<Drawable>* list)
{
    return static_cast<Geode*>(list->object)->toOsg()->getNumDrawables();
}

void Geode::clear(QQmlListProperty<Drawable>* list)
{
    Geode* self = static_cast<Geode*>(list->object);
    self->drawables.clear();
    self->toOsg()->removeDrawables(0, self->toOsg()->getNumDrawables());
    self->drawableListChanged();
}
