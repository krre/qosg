#pragma once
#include <osg/Drawable>
#include <osg/RenderInfo>
#include <QObject>
#include "object.h"

class Drawable : public Object, public osg::Drawable
{
    Q_OBJECT
public:
    Drawable() {}
    void drawImplementation(osg::RenderInfo&) const {}
};

