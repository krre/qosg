#pragma once
#include <QtQml>
#include <osg/Group>
#include "Node.h"

class Group : public Node {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Node> childList READ childList NOTIFY childListChanged)
    Q_CLASSINFO("DefaultProperty", "childList")

public:
    void classBegin() override;
    osg::Group* toOsg() { return static_cast<osg::Group*>(osgObj.get()); }
    QQmlListProperty<Node> childList() { return QQmlListProperty<Node>(this, 0, Group::append, Group::count, Group::at, Group::clear); }

    Q_INVOKABLE void addChild(Node *child);
    Q_INVOKABLE Node* getChild(unsigned int i);
    Q_INVOKABLE unsigned int getNumChildren();
    Q_INVOKABLE void removeChild(Node* child);
    Q_INVOKABLE void removeChildren();

signals:
    void childListChanged();

private:
    static void append(QQmlListProperty<Node>* list, Node* child);
    static Node* at(QQmlListProperty<Node>* list, int index);
    static int count(QQmlListProperty<Node>* list);
    static void clear(QQmlListProperty<Node>* list);
    QList<Node*> nodes;
};
