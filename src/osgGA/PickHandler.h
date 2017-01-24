#pragma once
#include <osgGA/GUIEventHandler>
#include <osgViewer/View>
#include <QObject>

class PickHandler : public QObject, public osgGA::GUIEventHandler {
    Q_OBJECT
public:
    bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);

signals:
    void picked(const QString& name);
};
