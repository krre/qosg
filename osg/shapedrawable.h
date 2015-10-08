#pragma once
#include <osg/ShapeDrawable>
#include <QObject>

class ShapeDrawable : public QObject, public osg::ShapeDrawable
{
    Q_OBJECT

public:
    ShapeDrawable() {}
};
