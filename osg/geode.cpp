#include "geode.h"

Geode::Geode()
{

}

void Geode::classBegin()
{
    if (obj == nullptr) {
        obj = new osg::Geode;
    }
    geode = static_cast<osg::Geode*>(obj);
    Node::classBegin();
}
