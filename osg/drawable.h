#pragma once
#include <QtCore>
#include "object.h"
#include <osg/Drawable>

class Drawable : public Object
{
    Q_OBJECT

public:
    Drawable();
    void classBegin() override;
    osg::Drawable* instance() { return drawable; }

private:
    osg::Drawable* drawable;
};
