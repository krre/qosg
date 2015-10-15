#pragma once
#include <QtQml>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include "../osg/node.h"

class OsgDb : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE Node* readNodeFile(const QString& filename);
    Q_INVOKABLE bool writeNodeFile(Node* node, const QString& filename);
};

