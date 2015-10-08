#pragma once
#include <QtCore>
#include <QtQml>
#include <osg/Object>

class Object : public QObject, QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)

public:
    Object();

protected:
    void classBegin();
    osg::Object* obj = nullptr;
};

