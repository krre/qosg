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
    $$(OSG_HOME)/include

HEADERS += \
    src/osgViewer/viewer.h \
    src/osg/node.h \
    src/osg/group.h \
    src/osg/transform.h \
    src/osg/box.h \
    src/osg/geode.h \
    src/osg/shapedrawable.h \
    src/osg/sphere.h \
    src/osg/drawable.h \
    src/osg/object.h \
    src/osg/shape.h \
    src/osgText/textbase.h \
    src/osgText/text.h \
    src/osgText/text3d.h \
    src/osg/camera.h \
    src/converter.h \
    src/osgDB/osgdb.h \
    src/osg/cylinder.h \
    src/osgGA/pickhandler.h \
    src/osg/positionattitudetransform.h \
    src/osg/boundingsphere.h \

SOURCES += \
    src/osgViewer/viewer.cpp \
    src/osg/node.cpp \
    src/osg/group.cpp \
    src/osg/transform.cpp \
    src/osg/box.cpp \
    src/osg/geode.cpp \
    src/osg/shapedrawable.cpp \
    src/osg/sphere.cpp \
    src/osg/drawable.cpp \
    src/osg/object.cpp \
    src/osg/shape.cpp \
    src/osgText/textbase.cpp \
    src/osgText/text.cpp \
    src/osgText/text3d.cpp \
    src/osg/camera.cpp \
    src/converter.cpp \
    src/osgDB/osgdb.cpp \
    src/osg/cylinder.cpp \
    src/osgGA/pickhandler.cpp \
    src/osg/positionattitudetransform.cpp \
    src/osg/boundingsphere.cpp \

DISTFILES += \
    README.md \
