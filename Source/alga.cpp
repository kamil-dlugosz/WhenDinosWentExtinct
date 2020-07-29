#include <QRandomGenerator>
#include "alga.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Alga::Alga(WorldMap *world_map, QPointF position, Kind kind)
  : Grass(world_map, position, kind)
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
    if (isInGoodBiome(getPosition()))
      break;
    if (i ++ > max)
      killMe();
  }
  setMaxFertility(2500);
}

Alga::~Alga()
{

}

void Alga::tick()
{
  Grass::tick();
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
