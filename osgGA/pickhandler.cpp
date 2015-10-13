#include "pickhandler.h"
#include "../converter.h"
#include <sstream>
#include <osg/io_utils>
#include <iostream>
#include <QDebug>

bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
    if (ea.getEventType() != osgGA::GUIEventAdapter::PUSH && ea.getButton() != osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON) {
        return false;
    }

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
            qDebug() << QString::fromStdString(intersection.nodePath.back()->getName());
            break;
        }
    }

    return true;
}
