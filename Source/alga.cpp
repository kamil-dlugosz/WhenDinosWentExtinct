#include <QRandomGenerator>
#include "alga.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Alga::Alga(WorldMap *world_map, Kind kind)
  : Grass(world_map, kind)
{
  QVector<Biome> allowed_biomes(2);
  allowed_biomes[0] = Biome::WATER;
  allowed_biomes[1] = Biome::DEEPWATER;
  setAllowedBiomes(allowed_biomes);
  int i = 0, max = 5;
  while (true) {
    setPosition(QPointF(QRandomGenerator::system()
                        ->bounded(quint32(0), quint32(getWorldMap()->pixelWidth())),
                        QRandomGenerator::system()
                        ->bounded(quint32(0), quint32(getWorldMap()->pixelHeight()))));
    if (isPointReachable(getPosition()))
      break;
    if (i ++ > max)
      killMe();
  }
}

Alga::~Alga()
{

}

void Alga::tick()
{
  Grass::tick();
}

int Alga::eatMe()
{
  return Plant::eatMe();
}

void Alga::spread()
{
  Grass::spread();
}

void Alga::grow()
{
  Grass::grow();
}
}
