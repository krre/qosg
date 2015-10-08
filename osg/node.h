#pragma once
#include <QtCore>
#include "object.h"
#include <osg/Node>

class Node : public Object
{
    Q_OBJECT

public:
    Node();
    void classBegin() override;
    osg::Node* instance() { return node; }

private:
    osg::Node* node;
};

