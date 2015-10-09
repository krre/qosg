#pragma once
#include <osg/Object>
#include <QObject>

class Object : public QObject, public osg::Object
{
    Q_OBJECT

public:
    Object() {}
    osg::Object* cloneType() const { return nullptr; }
    osg::Object* clone(const osg::CopyOp&) const { return nullptr; }
    const char* libraryName() const { return ""; }
    const char* className() const { return ""; }
};
