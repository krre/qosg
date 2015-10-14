#pragma once
#include <QColor>
#include <QVector3D>
#include <QString>
#include <QQuaternion>
#include <osg/Vec4>
#include <osg/Vec3>
#include <osgText/String>
#include <osg/Quat>

class Converter
{
public:
    Converter() {}
    static osg::Vec4 toVec4(const QColor& color);
    static QColor fromVec4(const osg::Vec4& vec4);

    static osg::Vec3 toVec3(const QVector3D& vector3d);
    static QVector3D fromVec3(const osg::Vec3& vec3);

    static osgText::String toOsgString(const QString& str);
    static QString fromOsgString(const osgText::String& str);

    static osg::Quat toQuat(const QQuaternion& quaternion);
    static QQuaternion fromQuat(const osg::Quat& quat);
};
