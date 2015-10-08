#pragma once
#include <QtCore>
#include <QtQml>
#include <osg/Object>

class Object : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)

public:
    Object();
    void classBegin() override;
    void componentComplete() override;
    osg::Object* instance() { return obj; }

protected:
    osg::Object* obj = nullptr;
};

