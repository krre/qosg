#pragma once
#include <QQmlParserStatus>
#include <osg/Object>
#include <QObject>
#include "../converter.h"

class Object : public QObject, public QQmlParserStatus {
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
public:
    void classBegin() override;
    void componentComplete() override {}
    osg::Object* toOsg() { return osgObj.get(); }

    QString getName() { return Converter::fromOsgString(toOsg()->getName()); }
    void setName(const QString& name);

signals:
    void nameChanged(QString name);

protected:
    osg::ref_ptr<osg::Object> osgObj = nullptr;
};
