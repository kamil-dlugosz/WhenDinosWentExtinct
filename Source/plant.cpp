#include "plant.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Plant::Plant(WorldMap *world_map, Kind kind)
  : AliveEntity(world_map, kind)
  , spread_rate_(1)
  , growth_rate_(5)
  , seed_number_(3)
{

}

Plant::~Plant()
{

}

void Plant::tick()
{

}

int Plant::eatMe()
{
  killMe();
  return 3000;
}

int Plant::getSpreadRate() const
{
  return spread_rate_;
}

int Plant::getGrowthRate() const
{
  return growth_rate_;
}

int Plant::getSeedNumber() const
{
  return seed_number_;
}
}
