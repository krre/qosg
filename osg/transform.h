#pragma once
#include <osg/Transform>
#include <QObject>

class Transform : public QObject, public osg::Transform
{
    Q_OBJECT

public:
    Transform() {}
};
