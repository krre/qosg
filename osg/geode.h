#pragma once
#include <QtCore>
#include "node.h"
#include <osg/Geode>

class Geode : public Node
{
    Q_OBJECT

public:
    Geode();
    void classBegin() override;
    osg::Geode* instance() { return geode; }

private:
    osg::Geode* geode;
};
