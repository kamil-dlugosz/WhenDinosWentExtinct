#include <QDebug>
#include "meteor.h"

namespace WDWE::logic::disasters
{
Meteor::Meteor(WorldMap *world_map)
  : Inferno(world_map, Type::METEOR)
{
  qDebug() << "con met";
}

Meteor::~Meteor()
{
  qDebug() << "des met";
}

void Meteor::tick()
{
  Inferno::tick();
}

void Meteor::meteorFall()
{

}
}
