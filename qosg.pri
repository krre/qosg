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
    $$PWD/src/osgViewer/viewer.h \
    $$PWD/src/osg/node.h \
    $$PWD/src/osg/group.h \
    $$PWD/src/osg/transform.h \
    $$PWD/src/osg/box.h \
    $$PWD/src/osg/geode.h \
    $$PWD/src/osg/shapedrawable.h \
    $$PWD/src/osg/sphere.h \
    $$PWD/src/osg/drawable.h \
    $$PWD/src/osg/object.h \
    $$PWD/src/osg/shape.h \
    $$PWD/src/osgText/textbase.h \
    $$PWD/src/osgText/text.h \
    $$PWD/src/osgText/text3d.h \
    $$PWD/src/osg/camera.h \
    $$PWD/src/converter.h \
    $$PWD/src/osgDB/osgdb.h \
    $$PWD/src/osg/cylinder.h \
    $$PWD/src/osgGA/pickhandler.h \
    $$PWD/src/osg/positionattitudetransform.h \
    $$PWD/src/osg/boundingsphere.h \
    $$PWD/src/registerosgtypes.h

SOURCES += \
    $$PWD/src/osgViewer/viewer.cpp \
    $$PWD/src/osg/node.cpp \
    $$PWD/src/osg/group.cpp \
    $$PWD/src/osg/transform.cpp \
    $$PWD/src/osg/box.cpp \
    $$PWD/src/osg/geode.cpp \
    $$PWD/src/osg/shapedrawable.cpp \
    $$PWD/src/osg/sphere.cpp \
    $$PWD/src/osg/drawable.cpp \
    $$PWD/src/osg/object.cpp \
    $$PWD/src/osg/shape.cpp \
    $$PWD/src/osgText/textbase.cpp \
    $$PWD/src/osgText/text.cpp \
    $$PWD/src/osgText/text3d.cpp \
    $$PWD/src/osg/camera.cpp \
    $$PWD/src/converter.cpp \
    $$PWD/src/osgDB/osgdb.cpp \
    $$PWD/src/osg/cylinder.cpp \
    $$PWD/src/osgGA/pickhandler.cpp \
    $$PWD/src/osg/positionattitudetransform.cpp \
    $$PWD/src/osg/boundingsphere.cpp \

DISTFILES += \
    $$PWD/README.md \
