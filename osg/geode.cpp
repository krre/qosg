#include "geode.h"

void Geode::append(QQmlListProperty<osg::Drawable>* list, osg::Drawable* drawable)
{
    if (!drawable) return;
    Geode* self = static_cast<Geode*>(list->object);
    self->addDrawable(drawable);
    self->drawableListChanged();
}

osg::Drawable* Geode::at(QQmlListProperty<osg::Drawable>* list, int index)
{
    return static_cast<Geode*>(list->object)->getDrawable(index);
}

int Geode::count(QQmlListProperty<osg::Drawable>* list)
{
    return static_cast<Geode*>(list->object)->getNumDrawables();
}

void Geode::clear(QQmlListProperty<osg::Drawable>* list)
{
    Geode* self = static_cast<Geode*>(list->object);
    self->removeDrawables(0, self->getNumDrawables());
    self->drawableListChanged();
}
