#pragma once
#include <osg/Group>
#include <QObject>

class Group : public QObject, public osg::Group
{
    Q_OBJECT

public:
    Group() {}
};
