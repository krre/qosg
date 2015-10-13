#include "camera.h"
#include <osg/Vec4>

void Camera::classBegin() {
    osgObj = new osg::Camera;
    Transform::classBegin();
}

void Camera::setClearColor(const QColor& clearColor)
{
    osg::Vec4 vec4 = Converter::toVec4(clearColor);
    if (vec4 == toOsg()->getClearColor()) return;
    toOsg()->setClearColor(vec4);
    emit clearColorChanged(clearColor);
}

double Camera::getFovy()
{
    return getLens()["fovy"];
}

void Camera::setFovy(double fovy)
{
    QMap<QString, double> lens = getLens();
    if (lens["fovy"] == fovy) return;
    lens["fovy"] = fovy;
    setLens(lens);
    emit fovyChanged(fovy);
}

double Camera::getAspectRatio()
{
    return getLens()["aspectRatio"];
}

void Camera::setAspectRatio(double aspectRatio)
{
    QMap<QString, double> lens = getLens();
    if (lens["aspectRatio"] == aspectRatio) return;
    lens["aspectRatio"] = aspectRatio;
    setLens(lens);
    emit aspectRatioChanged(aspectRatio);
}

double Camera::getZNear()
{
    return getLens()["zNear"];
}

void Camera::setZNear(double zNear)
{
    QMap<QString, double> lens = getLens();
    if (lens["zNear"] == zNear) return;
    lens["zNear"] = zNear;
    setLens(lens);
    emit zNearChanged(zNear);
}

double Camera::getZFar()
{
    return getLens()["zFar"];;
}

void Camera::setZFar(double zFar)
{
    QMap<QString, double> lens = getLens();
    if (lens["zFar"] == zFar) return;
    lens["zFar"] = zFar;
    setLens(lens);
    emit zFarChanged(zFar);
}

QMap<QString, double> Camera::getLens()
{
    QMap<QString, double> map;
    toOsg()->getProjectionMatrixAsPerspective(map["fovy"], map["aspectRatio"], map["zNear"], map["zFar"]);
    return map;
}

void Camera::setLens(const QMap<QString, double>& lens)
{
    toOsg()->setProjectionMatrixAsPerspective(lens["fovy"], lens["aspectRatio"], lens["zNear"], lens["zFar"]);
}
