#pragma once
#include <osg/Camera>
#include "transform.h"
#include <QColor>

class Camera : public Transform
{
    Q_OBJECT
    Q_PROPERTY(QColor clearColor READ getClearColor WRITE setClearColor NOTIFY clearColorChanged)

public:
    Camera() {}
    void classBegin() override;
    osg::Camera* toOsg() { return static_cast<osg::Camera*>(osgObj); }
    void fromOsg(osg::Camera* camera);

    QColor getClearColor();
    void setClearColor(QColor clearColor);
signals:
    void clearColorChanged(QColor clearColor);
};
