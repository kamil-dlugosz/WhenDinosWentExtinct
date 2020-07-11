#include <QDebug>
#include "inferno.h"

namespace WDWE::logic::disasters
{
Inferno::Inferno(WorldMap *world_map, Type type)
  : Disaster(world_map, type)
{
  qDebug() << "con inf";
}

Inferno::~Inferno()
{
  qDebug() << "des inf";
}

void Inferno::tick()
{
  Disaster::tick();
}

QPointF Inferno::getCenter()
{
  return center_;
}

int Inferno::getSpreadPace()
{
  return spread_pace_;
}

void Inferno::destroySoil()
{

}

void Inferno::spreadFire()
{

}
}
