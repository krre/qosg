#pragma once
#include <osg/Shape>
#include <QObject>

class Sphere : public QObject, public osg::Sphere
{
    Q_OBJECT
    Q_PROPERTY(float radius READ getRadius WRITE setRadius NOTIFY radiusChanged)

public:
    Sphere() {}

    void setRadius(float radius);

signals:
    void radiusChanged(float radius);
};
