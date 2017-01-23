#include "pickhandler.h"
#include "../converter.h"
#include <sstream>
#include <osg/io_utils>
#include <iostream>

bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) {
    int push = 1;
    if (ea.getEventType() != push) return false;

    int rightMouseButton = 0;
    if (ea.getButton() != rightMouseButton) return false;

    osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);

    if (viewer) {
        osg::Camera* camera = viewer->getCamera();
        if (!camera) return false;

        float x = ea.getX();
        float y = ea.getWindowHeight() * (1 - ea.getY() / ea.getWindowHeight()); // invert y position
        osgUtil::LineSegmentIntersector* intersector = new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, x, y);
        osgUtil::IntersectionVisitor iv(intersector);
        camera->accept(iv);

        if (!intersector->containsIntersections()) return false;

        auto intersections = intersector->getIntersections();
        for (auto&& intersection : intersections) {
            QString name = QString::fromStdString(intersection.nodePath.back()->getName());
            emit picked(name);
            break;
        }
    }

    return true;
}
