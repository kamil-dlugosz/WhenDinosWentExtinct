#include <QRandomGenerator>
#include <QDebug>
#include "drought.h"

namespace WDWE::logic::disasters
{
Drought::Drought(WorldMap *world_map, int duration, float drying_rate)
  : Disaster(world_map, duration, Type::DROUGHT)
  , drying_rate_(drying_rate)
{

}

Drought::~Drought()
{

}

void Drought::tick()
{
  getDryingRate();
  Disaster::tick();
  dryingBiomes();
}

int Drought::getDryingRate() const
{
  return drying_rate_;
}

void Drought::dryingBiomes()
{
  for (int x = 0; x < getWorldMap()->tileWidth(); ++ x)
    for (int y = 0; y < getWorldMap()->tileHeight(); ++ y) {
      if (getDryingRate() < QRandomGenerator::system()->bounded(100))
        continue;
      switch (getWorldMap()->biomeAtTile(x, y)) {
      case Biome::FOREST:
        if (checkNeighbours(Biome::SAVANNA, x, y))
          getWorldMap()->biomeChange(Biome::SAVANNA, x, y, false);
        break;
      case Biome::SAVANNA:
        if (checkNeighbours(Biome::SAND, x, y))
          getWorldMap()->biomeChange(Biome::SAND, x, y, false);
        break;
      case Biome::DEEPWATER:
        if (checkNeighbours(Biome::WATER, x, y))
          getWorldMap()->biomeChange(Biome::WATER, x, y, false);
        break;
      case Biome::WATER:
        if (checkNeighbours(Biome::SAND, x, y))
          getWorldMap()->biomeChange(Biome::SAND, x, y, false);
        break;
      default:
        break;
      }}
}

bool Drought::checkNeighbours(Biome biome, int x, int y)
{
  if (x < 0 || x >= getWorldMap()->tileWidth() ||
      y < 0 || y >= getWorldMap()->tileHeight())
    return false;
  if (x > 0 &&
      getWorldMap()->biomeAtTile(x-1, y) == biome)
    return true;
  else if (y > 0 &&
           getWorldMap()->biomeAtTile(x, y-1) == biome)
    return true;
  else if (x  < getWorldMap()->tileWidth() &&
           getWorldMap()->biomeAtTile(x+1, y) == biome)
    return true;
  else if (y < getWorldMap()->tileHeight() &&
           getWorldMap()->biomeAtTile(x, y+1) == biome)
    return true;
  else
    return false;
}
}
