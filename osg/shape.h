#pragma once
#include <QtCore>
#include "object.h"
#include <osg/Shape>

class Shape : public Object
{
    Q_OBJECT

public:
    Shape();
    void classBegin() override;

private:
    osg::Shape* shape;
};
