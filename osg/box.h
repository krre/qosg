#pragma once
#include <osg/Shape>
#include <QObject>

class Box : public QObject, public osg::Box
{
    Q_OBJECT

public:
    Box() {}
};
