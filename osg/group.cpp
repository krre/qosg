#include "group.h"

void Group::classBegin()
{
    if (osgObj == nullptr) {
        osgObj = new osg::Group;
    }
    Node::classBegin();
}

void Group::addChild(Node* child)
{
    nodes.append(child);
    toOsg()->addChild(child->toOsg());
    childListChanged();
}

Node* Group::getChild(unsigned int i)
{
    return nodes.at(i);
}

unsigned int Group::getNumChildren()
{
    return nodes.count();
}

void Group::removeChild(Node* child)
{
    nodes.removeOne(child);
    toOsg()->removeChild(child->toOsg());
}

void Group::removeChildren()
{
    nodes.clear();
    toOsg()->removeChildren(0, toOsg()->getNumChildren());
    childListChanged();
}

void Group::append(QQmlListProperty<Node>* list, Node* child)
{
    if (!child) return;
    static_cast<Group*>(list->object)->addChild(child);
}

Node* Group::at(QQmlListProperty<Node>* list, int index)
{
    return static_cast<Group*>(list->object)->getChild(index);
}

int Group::count(QQmlListProperty<Node>* list)
{
    return static_cast<Group*>(list->object)->getNumChildren();
}

void Group::clear(QQmlListProperty<Node>* list)
{
    static_cast<Group*>(list->object)->removeChildren();

}
