#include "object.h"
#include <QDebug>

void Object::classBegin()
{
//    qDebug() << this;
}

void Object::setName(const QString& name)
{
    if (toOsg()->getName() == name.toStdString()) return;
    toOsg()->setName(name.toStdString());
    emit nameChanged(name);
}
