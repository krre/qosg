#pragma once
#include <osgGA/GUIEventHandler>
#include <osgViewer/View>

class PickHandler : public osgGA::GUIEventHandler {
public:
    PickHandler() {}
    ~PickHandler() {}
    bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
};

