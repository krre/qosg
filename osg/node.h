#pragma once
#include <osg/Node>
#include <QObject>
#include "object.h"

class Node : public QObject, public osg::Node
{
    Q_OBJECT

public:
    Node() {}
};
