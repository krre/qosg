#pragma once
#include <QQmlParserStatus>
#include <osg/Object>
#include <QObject>

class Object : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)

public:
    Object() {}
    void classBegin() override {}
    void componentComplete() override {}
    osg::Object* toOsg() { return osgObj; }

protected:
    osg::Object* osgObj = nullptr;
};
