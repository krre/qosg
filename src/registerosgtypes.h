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

static QObject* osgdb_singletontype_provider(QQmlEngine* engine, QJSEngine* scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return new OsgDb();
}

static void registerOsgTypes() {
    // osg
    qmlRegisterType<Viewer>("Osg", 1, 0, "Viewer");
    qmlRegisterType<Node>("Osg", 1, 0, "Node");
    qmlRegisterType<Geode>("Osg", 1, 0, "Geode");
    qmlRegisterType<Group>("Osg", 1, 0, "Group");
    qmlRegisterType<Transform>("Osg", 1, 0, "Transform");
    qmlRegisterType<PositionAttitudeTransform>("Osg", 1, 0, "PositionAttitudeTransform");
    qmlRegisterType<ShapeDrawable>("Osg", 1, 0, "ShapeDrawable");
    qmlRegisterType<Box>("Osg", 1, 0, "Box");
    qmlRegisterType<Sphere>("Osg", 1, 0, "Sphere");
    qmlRegisterType<Cylinder>("Osg", 1, 0, "Cylinder");
    qmlRegisterType<Camera>("Osg", 1, 0, "Camera");
    qmlRegisterUncreatableType<Object>("Osg", 1, 0, "Object", "Object is uncreatable type");
    qmlRegisterUncreatableType<Drawable>("Osg", 1, 0, "Drawable", "Drawable is uncreatable type");
    qmlRegisterUncreatableType<Shape>("Osg", 1, 0, "Shape", "Shape is uncreatable type");
    qmlRegisterUncreatableType<BoundingSphere>("Osg", 1, 0, "BoundingSphere", "BoundingSphere is uncreatable type");

    // osgText
    qmlRegisterType<Text>("Osg", 1, 0, "Text");
    qmlRegisterType<Text3D>("Osg", 1, 0, "Text3D");
    qmlRegisterUncreatableType<TextBase>("Osg", 1, 0, "TextBase", "TextBase is uncreatable type");

    // osgDB
    qmlRegisterSingletonType<OsgDb>("Osg", 1, 0, "OsgDb", osgdb_singletontype_provider);
}
