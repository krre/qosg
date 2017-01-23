#pragma once
#include <QObject>
#include <osg/BoundingSphere>
#include <osg/ref_ptr>
#include "../converter.h"

class BoundingSphere : public QObject {
    Q_OBJECT
    Q_PROPERTY(float radius READ getRadius CONSTANT)
    Q_PROPERTY(QVector3D center READ getCenter CONSTANT)

public:
    void setBound(osg::BoundingSphere bs) { this->bs = bs; }

    float getRadius() { return bs.radius(); }
    QVector3D getCenter() { return Converter::fromVec3(bs.center()); }

private:
    osg::BoundingSphere bs;
};
