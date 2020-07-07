#include "bush.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Bush::Bush(WorldMap *world_map, Kind kind)
  : Tree(world_map, kind)
{

}

Bush::~Bush()
{

}

void Bush::tick()
{

}

int Bush::eatMe()
{
  return Plant::eatMe();
}

void Bush::spread()
{

}

void Bush::grow()
{

}
}
