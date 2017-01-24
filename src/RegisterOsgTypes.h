#pragma once
#include <QtQml>

#include "osgViewer/Viewer.h"
#include "osg/Object.h"
#include "osg/Node.h"
#include "osg/Geode.h"
#include "osg/Group.h"
#include "osg/Transform.h"
#include "osg/PositionAttitudeTransform.h"
#include "osg/Drawable.h"
#include "osg/Shape.h"
#include "osg/ShapeDrawable.h"
#include "osg/Box.h"
#include "osg/Sphere.h"
#include "osg/Cylinder.h"
#include "osg/Camera.h"
#include "osg/BoundingSphere.h"
#include "osgText/TextBase.h"
#include "osgText/Text.h"
#include "osgText/Text3D.h"
#include "osgDB/OsgDb.h"

static QObject* osgdb_singletontype_provider(QQmlEngine* engine, QJSEngine* scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return new OsgDb();
}

static void registerOsgTypes() {
    // osg
    qmlRegisterType<Viewer>("QOsg", 0, 1, "Viewer");
    qmlRegisterType<Node>("QOsg", 0, 1, "Node");
    qmlRegisterType<Geode>("QOsg", 0, 1, "Geode");
    qmlRegisterType<Group>("QOsg", 0, 1, "Group");
    qmlRegisterType<Transform>("QOsg", 0, 1, "Transform");
    qmlRegisterType<PositionAttitudeTransform>("QOsg", 0, 1, "PositionAttitudeTransform");
    qmlRegisterType<ShapeDrawable>("QOsg", 0, 1, "ShapeDrawable");
    qmlRegisterType<Box>("QOsg", 0, 1, "Box");
    qmlRegisterType<Sphere>("QOsg", 0, 1, "Sphere");
    qmlRegisterType<Cylinder>("QOsg", 0, 1, "Cylinder");
    qmlRegisterType<Camera>("QOsg", 0, 1, "Camera");
    qmlRegisterUncreatableType<Object>("QOsg", 0, 1, "Object", "Object is uncreatable type");
    qmlRegisterUncreatableType<Drawable>("QOsg", 0, 1, "Drawable", "Drawable is uncreatable type");
    qmlRegisterUncreatableType<Shape>("QOsg", 0, 1, "Shape", "Shape is uncreatable type");
    qmlRegisterUncreatableType<BoundingSphere>("QOsg", 0, 1, "BoundingSphere", "BoundingSphere is uncreatable type");

    // osgText
    qmlRegisterType<Text>("QOsg", 0, 1, "Text");
    qmlRegisterType<Text3D>("QOsg", 0, 1, "Text3D");
    qmlRegisterUncreatableType<TextBase>("QOsg", 0, 1, "TextBase", "TextBase is uncreatable type");

    // osgDB
    qmlRegisterSingletonType<OsgDb>("QOsg", 0, 1, "OsgDb", osgdb_singletontype_provider);
}
