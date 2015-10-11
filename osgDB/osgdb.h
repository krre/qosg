#pragma once
#include <QtQml>
#include <osgDb/ReadFile>
#include <osgDb/WriteFile>
#include "../osg/node.h"

class OsgDb : public QObject
{
    Q_OBJECT

public:
    OsgDb() {}
    Q_INVOKABLE Node* readNodeFile(const QString& filename);
    Q_INVOKABLE bool writeNodeFile(Node* node, const QString& filename);
};

