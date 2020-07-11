#include <QDebug>
#include "disaster.h"

namespace WDWE::logic::disasters
{
Disaster::Disaster(WorldMap *world_map, Type type)
  : world_map_(world_map)
  , type_(type)
  , duration_total_(100)
  , duration_left_(duration_total_)
{
  qDebug() << "con dis";
}

Disaster::~Disaster()
{
  qDebug() << "des dis";
}

void Disaster::tick()
{
  qDebug() << -- duration_left_;
}

WorldMap *Disaster::getWorldMap() const
{
  return world_map_;
}

int Disaster::getDurationTotal() const
{
  return duration_total_;
}

int Disaster::getDurationLeft() const
{
  return duration_left_;
}

Type Disaster::getType() const
{
  return type_;
}

bool Disaster::hasEnded() const
{
  return (duration_left_ <= 0);
}
}
