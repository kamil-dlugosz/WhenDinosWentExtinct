#include "alga.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Alga::Alga(WorldMap *world_map, Kind kind)
  : Grass(world_map, kind)
{

}

Alga::~Alga()
{

}

void Alga::tick()
{

}

int Alga::eatMe()
{
  return Plant::eatMe();
}

void Alga::spread()
{

}

void Alga::grow()
{

}
}
