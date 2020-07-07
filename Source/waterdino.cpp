#include "waterdino.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
WaterDino::WaterDino(WorldMap *world_map, Kind kind)
  : Dino(world_map, kind)
{

}

WaterDino::~WaterDino()
{

}

void WaterDino::tick()
{
  Dino::tick();
}

Entity *WaterDino::findFood()
{
  return Dino::findFood();
}

Entity *WaterDino::findMate()
{

}

void WaterDino::eat()
{

}

void WaterDino::mating()
{

}

void WaterDino::pair(Entity *target)
{

}

void WaterDino::unpair()
{

}

void WaterDino::takeABreath()
{

}

bool WaterDino::move()
{
  return Dino::move();
}
}
