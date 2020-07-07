#include "landdino.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
LandDino::LandDino(WorldMap *world_map, Kind kind)
  : Dino(world_map, kind)
{

}

LandDino::~LandDino()
{

}

void LandDino::tick()
{
  Dino::tick();
}

Entity *LandDino::findFood()
{
  return Dino::findFood();
}

Entity *LandDino::findMate()
{

}

void LandDino::eat()
{

}

void LandDino::mating()
{

}

void LandDino::pair(Entity *target)
{

}

void LandDino::unpair()
{

}

bool LandDino::move()
{
  return Dino::move();
}
}
