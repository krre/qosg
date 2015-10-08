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
    osg::Group* instance() { return group; }

private:
    osg::Group* group;
};
