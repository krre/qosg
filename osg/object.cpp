#include "object.h"

void Object::setName(const QString& name)
{
    if (toOsg()->getName() == name.toStdString()) return;
    toOsg()->setName(name.toStdString());
    emit nameChanged(name);
}
