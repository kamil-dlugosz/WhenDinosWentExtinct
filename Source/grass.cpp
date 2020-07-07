#include "grass.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Grass::Grass(WorldMap *world_map, Kind kind)
  : Plant(world_map, kind)
{

}

Grass::~Grass()
{

}

void Grass::tick()
{

}

int Grass::eatMe()
{
  return Plant::eatMe();
}

void Grass::spread()
{

}

void Grass::grow()
{

}
}
