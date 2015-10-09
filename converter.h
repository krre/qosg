#pragma once
#include <QColor>
#include <QVector3D>
#include <osg/Vec4>
#include <osg/Vec3>

class Converter
{
public:
    Converter() {}
    static osg::Vec4 toVec4(const QColor& color);
    static QColor fromVec4(const osg::Vec4& vec4);
    static osg::Vec3 toVec3(const QVector3D& vector3d);
    static QVector3D fromVec3(const osg::Vec3& vec3);
};

