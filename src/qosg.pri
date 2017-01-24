QT += opengl qml quick

CONFIG += c++11

LIBS += \
    -L$$(OSG_HOME)/lib \
    -L$$(OSG_HOME)/lib64

CONFIG(debug, debug|release) {
    LIBS += -losgd -losgViewerd -losgGAd -losgDBd -losgUtild -losgTextd -lOpenThreadsd
} else {
    LIBS += -losg -losgViewer -losgGA -losgDB -losgUtil -losgText -lOpenThreads
}

INCLUDEPATH += \
    $$PWD \
    $$(OSG_HOME)/include

DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/osg/BoundingSphere.h \
    $$PWD/osg/Box.h \
    $$PWD/osg/Camera.h \
    $$PWD/osg/Cylinder.h \
    $$PWD/osg/Drawable.h \
    $$PWD/osg/Geode.h \
    $$PWD/osg/Group.h \
    $$PWD/osg/Node.h \
    $$PWD/osg/Object.h \
    $$PWD/osg/PositionAttitudeTransform.h \
    $$PWD/osg/Shape.h \
    $$PWD/osg/ShapeDrawable.h \
    $$PWD/osg/Sphere.h \
    $$PWD/osg/Transform.h \
    $$PWD/osgDB/OsgDb.h \
    $$PWD/osgGA/PickHandler.h \
    $$PWD/osgText/Text.h \
    $$PWD/osgText/Text3D.h \
    $$PWD/osgText/TextBase.h \
    $$PWD/osgViewer/Viewer.h \
    $$PWD/Converter.h \
    $$PWD/RegisterOsgTypes.h

SOURCES += \
    $$PWD/osg/BoundingSphere.cpp \
    $$PWD/osg/Box.cpp \
    $$PWD/osg/Camera.cpp \
    $$PWD/osg/Cylinder.cpp \
    $$PWD/osg/Drawable.cpp \
    $$PWD/osg/Geode.cpp \
    $$PWD/osg/Group.cpp \
    $$PWD/osg/Node.cpp \
    $$PWD/osg/Object.cpp \
    $$PWD/osg/PositionAttitudeTransform.cpp \
    $$PWD/osg/Shape.cpp \
    $$PWD/osg/ShapeDrawable.cpp \
    $$PWD/osg/Sphere.cpp \
    $$PWD/osg/Transform.cpp \
    $$PWD/osgDB/OsgDb.cpp \
    $$PWD/osgGA/PickHandler.cpp \
    $$PWD/osgText/Text.cpp \
    $$PWD/osgText/Text3D.cpp \
    $$PWD/osgText/TextBase.cpp \
    $$PWD/osgViewer/Viewer.cpp \
    $$PWD/Converter.cpp

DISTFILES += \
    $$PWD/../README.md \
