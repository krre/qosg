#pragma once
#include <QtCore>
#include "node.h"
#include <osg/Group>

class Group : public Node
{
    Q_OBJECT

public:
    Group();
    void classBegin() override;

private:
    osg::Group* group;
};
