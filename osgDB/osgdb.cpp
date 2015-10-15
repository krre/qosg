#include "osgdb.h"

Node* OsgDb::readNodeFile(const QString& filename) {
    Node* node = new Node();
    node->fromOsg(osgDB::readNodeFile(filename.toStdString()));
    return node;
}

bool OsgDb::writeNodeFile(Node* node, const QString& filename)
{
    return osgDB::writeNodeFile(*(node->toOsg()), filename.toStdString());
}
