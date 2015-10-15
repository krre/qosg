#include "object.h"
#include <inttypes.h>
#include <stdint.h>

void Object::classBegin()
{
    // Default name is class name plus object address
    QString name;
    name.sprintf("%08" PRIxPTR, (uintptr_t)this);
    name = metaObject()->className() + QString("(") + name + QString(")");
    setName(name);
}

void Object::setName(const QString& name)
{
    if (toOsg()->getName() == name.toStdString()) return;
    toOsg()->setName(name.toStdString());
    emit nameChanged(name);
}
