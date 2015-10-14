#include "converter.h"

osg::Vec4 Converter::toVec4(const QColor& color)
{
    return osg::Vec4(color.redF(), color.greenF(), color.blueF(), color.alphaF());
}

QColor Converter::fromVec4(const osg::Vec4& vec4)
{
    return QColor::fromRgbF(vec4.r(), vec4.g(), vec4.b(), vec4.a());
}

osg::Vec3 Converter::toVec3(const QVector3D& vector3d)
{
    return osg::Vec3(vector3d.x(), vector3d.y(), vector3d.z());
}

QVector3D Converter::fromVec3(const osg::Vec3& vec3)
{
    return QVector3D(vec3.x(), vec3.y(), vec3.z());
}

osgText::String Converter::toOsgString(const QString& str)
{
    return  osgText::String(str.toStdString(), osgText::String::ENCODING_UTF8);
}

QString Converter::fromOsgString(const osgText::String& str)
{
    return QString::fromStdString(str.createUTF8EncodedString());
}

osg::Quat Converter::toQuat(const QQuaternion& quaternion)
{
    return osg::Quat(quaternion.x(), quaternion.y(), quaternion.z(), quaternion.scalar());
}

QQuaternion Converter::forQuat(const osg::Quat& quat)
{
    return QQuaternion(quat.w(), quat.x(), quat.y(), quat.z());
}
