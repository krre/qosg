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
    $$PWD/osgViewer/viewer.h \
    $$PWD/osg/node.h \
    $$PWD/osg/group.h \
    $$PWD/osg/transform.h \
    $$PWD/osg/box.h \
    $$PWD/osg/geode.h \
    $$PWD/osg/shapedrawable.h \
    $$PWD/osg/sphere.h \
    $$PWD/osg/drawable.h \
    $$PWD/osg/object.h \
    $$PWD/osg/shape.h \
    $$PWD/osgText/textbase.h \
    $$PWD/osgText/text.h \
    $$PWD/osgText/text3d.h \
    $$PWD/osg/camera.h \
    $$PWD/converter.h \
    $$PWD/osgDB/osgdb.h \
    $$PWD/osg/cylinder.h \
    $$PWD/osgGA/pickhandler.h \
    $$PWD/osg/positionattitudetransform.h \
    $$PWD/osg/boundingsphere.h \
    $$PWD/registerosgtypes.h

SOURCES += \
    $$PWD/osgViewer/viewer.cpp \
    $$PWD/osg/node.cpp \
    $$PWD/osg/group.cpp \
    $$PWD/osg/transform.cpp \
    $$PWD/osg/box.cpp \
    $$PWD/osg/geode.cpp \
    $$PWD/osg/shapedrawable.cpp \
    $$PWD/osg/sphere.cpp \
    $$PWD/osg/drawable.cpp \
    $$PWD/osg/object.cpp \
    $$PWD/osg/shape.cpp \
    $$PWD/osgText/textbase.cpp \
    $$PWD/osgText/text.cpp \
    $$PWD/osgText/text3d.cpp \
    $$PWD/osg/camera.cpp \
    $$PWD/converter.cpp \
    $$PWD/osgDB/osgdb.cpp \
    $$PWD/osg/cylinder.cpp \
    $$PWD/osgGA/pickhandler.cpp \
    $$PWD/osg/positionattitudetransform.cpp \
    $$PWD/osg/boundingsphere.cpp \

DISTFILES += \
    $$PWD/README.md \
