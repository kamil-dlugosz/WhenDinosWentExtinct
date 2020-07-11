#include <QRandomGenerator>
#include "grass.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Grass::Grass(WorldMap *world_map, Kind kind)
  : Plant(world_map, kind)
  , lenght_(1)
  , max_lenght_(10)
  , nutrient_per_piece_(250)
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
    if (isPointReachable(getPosition()))
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
  spread();
  grow();
  incAge();
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
  if (isFertile()) {
    for (int i = 0; i < getSeedNumber(); ++ i)
      getWorldMap()->entityAdd(getKind());
    resetFertility();
  }
  incFertility(getSpreadRate());
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

bool Grass::isSaturated() const
{
  return getSaturation() >= getMaxSaturation();
}

void Grass::incLenght(int value)
{
  lenght_ += value;
  if (getLenght() > getMaxLenght())
    lenght_ = max_lenght_;
}
}
