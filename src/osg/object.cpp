#include "object.h"

void Object::classBegin()
{
    // Default name is class name plus object pointer
    QString ptr = QString("0x%1").arg((quintptr)this, QT_POINTER_SIZE * 2, 16, QChar('0'));
    QString name = metaObject()->className() + QString("(") + ptr + QString(")");
    setName(name);
}

void Object::setName(const QString& name)
{
    if (toOsg()->getName() == name.toStdString()) return;
    toOsg()->setName(name.toStdString());
    emit nameChanged(name);
}
