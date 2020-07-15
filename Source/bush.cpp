#include <QRandomGenerator>
#include "bush.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Bush::Bush(WorldMap *world_map, QPointF position, Kind kind)
  : Tree(world_map, position, kind)
{
  QVector<Biome> allowed_biomes(2);
  allowed_biomes[0] = Biome::SAVANNA;
  allowed_biomes[1] = Biome::FOREST;
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
  setMaxFertility(5000);
}

Bush::~Bush()
{

}

void Bush::tick()
{
  Tree::tick();
}

int Bush::eatMe()
{
  return Plant::eatMe();
}

void Bush::spread()
{
  Tree::spread();
}

void Bush::grow()
{
  Tree::spread();
}
}
