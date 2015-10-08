#pragma once
#include <osg/Node>
#include <QObject>

class Node : public QObject, public osg::Node
{
    Q_OBJECT

public:
    Node() {}
};
