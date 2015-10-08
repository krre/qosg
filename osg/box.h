#pragma once
#include <QtCore>
#include "shape.h"
#include <osg/Shape>

class Box : public Shape
{
    Q_OBJECT

public:
    Box();
    void classBegin() override;

private:
    osg::Box* box;
};
