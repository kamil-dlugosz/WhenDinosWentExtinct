#include "plant.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Plant::Plant(WorldMap *world_map, Kind kind)
  : Entity(world_map, kind)
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
}
