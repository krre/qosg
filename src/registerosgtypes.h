#pragma once
#include <QtQml>

#include "osgViewer/viewer.h"
#include "osg/object.h"
#include "osg/node.h"
#include "osg/geode.h"
#include "osg/group.h"
#include "osg/transform.h"
#include "osg/positionattitudetransform.h"
#include "osg/drawable.h"
#include "osg/shape.h"
#include "osg/shapedrawable.h"
#include "osg/box.h"
#include "osg/sphere.h"
#include "osg/cylinder.h"
#include "osg/camera.h"
#include "osg/boundingsphere.h"
#include "osgText/textbase.h"
#include "osgText/text.h"
#include "osgText/text3d.h"
#include "osgDB/osgdb.h"

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
