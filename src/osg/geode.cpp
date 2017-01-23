#include "geode.h"

void Geode::classBegin() {
    if (osgObj == nullptr) {
        osgObj = new osg::Geode;
    }
    Node::classBegin();
}

void Geode::componentComplete() {

}

void Geode::addDrawable(Drawable* drawable) {
    drawables.append(drawable);
    toOsg()->addDrawable(drawable->toOsg());
    drawableListChanged();
}

Drawable *Geode::getDrawable(unsigned int i) {
    return drawables.at(i);
}

unsigned int Geode::getNumDrawables() {
    return drawables.count();
}

void Geode::removeDrawable(Drawable* drawable) {
    drawables.removeOne(drawable);
    toOsg()->removeDrawable(drawable->toOsg());
}

void Geode::removeDrawables() {
    drawables.clear();
    toOsg()->removeDrawables(0, toOsg()->getNumDrawables());
    drawableListChanged();
}

void Geode::append(QQmlListProperty<Drawable>* list, Drawable* drawable) {
    if (!drawable) return;
    static_cast<Geode*>(list->object)->addDrawable(drawable);
}

Drawable* Geode::at(QQmlListProperty<Drawable>* list, int index) {
    return static_cast<Geode*>(list->object)->getDrawable(index);
}

int Geode::count(QQmlListProperty<Drawable>* list) {
    return static_cast<Geode*>(list->object)->getNumDrawables();
}

void Geode::clear(QQmlListProperty<Drawable>* list) {
    static_cast<Geode*>(list->object)->removeDrawables();

}
