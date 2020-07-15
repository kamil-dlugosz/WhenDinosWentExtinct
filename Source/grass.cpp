#include <QRandomGenerator>
#include "grass.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Grass::Grass(WorldMap *world_map, QPointF position, Kind kind)
  : Plant(world_map, position, kind)
  , lenght_(1)
  , max_lenght_(10)
  , nutrient_per_piece_(350)
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
}

Grass::~Grass()
{

}

void Grass::tick()
{
  Plant::tick();
}

int Grass::eatMe()
{
  incLenght(-1);
  if (getLenght() <= 0)
    killMe();
  return getNutrientPerPiece();
}

void Grass::spread()
{
  Plant::spread();
}

void Grass::grow()
{
  if (isSaturated()) {
    incLenght();
    setSaturation();
  }
  incSaturation(getGrowthRate());
}

int Grass::getLenght() const
{
  return lenght_;
}

int Grass::getMaxLenght() const
{
  return max_lenght_;
}

int Grass::getNutrientPerPiece() const
{
  return nutrient_per_piece_;
}

void Grass::incLenght(int value)
{
  lenght_ += value;
  if (getLenght() > getMaxLenght())
    lenght_ = max_lenght_;
}
}
