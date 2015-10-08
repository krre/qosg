#include "geode.h"

Geode::Geode()
{

}

void Geode::classBegin()
{
    if (obj == nullptr) {
        obj = new osg::Geode;
    }
    geode = static_cast<osg::Geode*>(obj);
    Node::classBegin();
}

void Geode::append(QQmlListProperty<Drawable>* list, Drawable* drawable)
{
    if (!drawable) {
        return;
    }
    Geode* self = static_cast<Geode*>(list->object);
    self->geode->addDrawable(drawable->instance());
    self->drawableListChanged();
}

Drawable* Geode::at(QQmlListProperty<Drawable>* list, int index)
{
    Geode* self = static_cast<Geode*>(list->object);
    return self->geode->getDrawable(index);
}

int Geode::count(QQmlListProperty<Drawable>* list)
{
    Geode* self = static_cast<Geode*>(list->object);
    return self->geode->getNumDrawables();
}

void Geode::clear(QQmlListProperty<Drawable>* list)
{
    Geode* self = static_cast<Geode*>(list->object);
    self->geode->removeDrawables(0, self->geode->getNumDrawables());
    self->drawableListChanged();
}
