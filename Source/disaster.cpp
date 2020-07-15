#include <QDebug>
#include "disaster.h"

namespace WDWE::logic::disasters
{
Disaster::Disaster(WorldMap *world_map, int duration, Type type)
  : world_map_(world_map)
  , type_(type)
  , duration_total_(duration)
  , duration_left_(duration_total_)
{

}

Disaster::~Disaster()
{

}

void Disaster::tick()
{
  -- duration_left_;
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

void Disaster::endDisaster()
{
  duration_left_ = 0;
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
