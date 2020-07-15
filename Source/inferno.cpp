#include <QDebug>
#include <QRandomGenerator>
#include "inferno.h"

namespace WDWE::logic::disasters
{
Inferno::Inferno(WorldMap *world_map, int duration, int max_size, float spread_pace,
                 Type type)
  : Disaster(world_map, duration, type)
  , center_(QPointF(QRandomGenerator::system()
                    ->bounded(quint32(0), quint32(getWorldMap()->pixelWidth())),
                    QRandomGenerator::system()
                    ->bounded(quint32(0), quint32(getWorldMap()->pixelHeight()))))
  , max_size_(max_size)
  , size_(0)
  , spread_pace_(spread_pace)
{

}

Inferno::~Inferno()
{

}

void Inferno::tick()
{
  Disaster::tick();
  incSize(spread_pace_);
  killEntities();
  destroySoil();
}

QPointF Inferno::getCenter()
{
  return center_;
}

void Inferno::setCenter(QPointF new_center)
{
  center_ = new_center;
}

int Inferno::getSpreadPace() const
{
  return spread_pace_;
}

int Inferno::getSize() const
{
  return size_;
}

int Inferno::getMaxSize() const
{
  return max_size_;
}

void Inferno::destroySoil()
{
  int ratio = getWorldMap()->tileSize();
  for (int x = 0; x < getWorldMap()->tileWidth(); ++ x)
    for (int y = 0; y < getWorldMap()->tileHeight(); ++ y) {
      float current_distance
          = (QPointF(x * ratio, y * ratio) - getCenter()).manhattanLength();
      if (current_distance < getSize() &&
          (getWorldMap()->biomeAtTile(x, y) == Biome::SAVANNA ||
           getWorldMap()->biomeAtTile(x, y) == Biome::FOREST))
        getWorldMap()->biomeChange(Biome::SAND, x, y, false);
    }
}

void Inferno::killEntities()
{
  for (int i = 0; i < getWorldMap()->entityNumber(); ++ i) {
    float current_distance
        = (getWorldMap()->positionAt(i) - getCenter()).manhattanLength();
    if (current_distance < size_)
      getWorldMap()->entityErase(i);
  }
}

void Inferno::incSize(float value)
{
  size_ += value;
  if (size_ > max_size_)
    size_ = max_size_;
}
}
