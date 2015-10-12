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
      osgUtil::LineSegmentIntersector* intersector = new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, ea.getX(), ea.getY());
      osgUtil::IntersectionVisitor iv(intersector);

      osg::Camera* camera = viewer->getCamera();
      if (!camera) return false;
      camera->accept(iv);

      if (!intersector->containsIntersections()) return false;

      auto intersections = intersector->getIntersections();

      qDebug() << "Got " << intersections.size() << " intersections:";

      for(auto&& intersection : intersections) {
        qDebug() << "  - Local intersection point = " << Converter::fromVec3(intersection.localIntersectionPoint)
                 << "name = " << QString::fromStdString(intersection.nodePath.back()->getName());
      }
    }

    return true;
}
