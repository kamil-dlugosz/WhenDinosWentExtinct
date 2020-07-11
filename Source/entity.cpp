#include <QDebug>
#include <QRandomGenerator>
#include "entity.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
AliveEntity::AliveEntity(WorldMap *world_map, Kind kind)
  : world_map_(world_map)
  , kind_(kind)
  , max_age_(7000)
  , max_fertility_(400)
  , max_saturation_(4000)
  , age_(0)
  , fertility_(0)
  , saturation_(3500)
  , position_(QPoint(0 ,0))
  , is_alive_(true)
{

}

AliveEntity::~AliveEntity()
{

}

void AliveEntity::tick()
{

}

Kind AliveEntity::getKind() const
{
  return kind_;
}

QPointF AliveEntity::getPosition() const
{
  return position_;
}

int AliveEntity::getAge() const
{
  return age_;
}

int AliveEntity::getFertility() const
{
  return fertility_;
}

bool AliveEntity::isAlive() const
{
  return is_alive_;
}

bool AliveEntity::isFertile()
{
  return (fertility_ >= max_fertility_);
}

bool AliveEntity::incFertility(int value)
{
  if (!isAdult())
    return false;
  fertility_ += value;
  return true;;
}

void AliveEntity::incSaturation(int value)
{
  saturation_ += value;
  if (saturation_ > max_saturation_)
    saturation_ = max_saturation_;
}

bool AliveEntity::incAge(int value)
{
  age_ += value;
  if (getAge() > getMaxAge()) {
    killMe();
    return false;
  }
  return true;
}

void AliveEntity::resetFertility()
{
  fertility_ = 0;
}

void AliveEntity::setSaturation(int value)
{
  saturation_ = value;
}

WorldMap *AliveEntity::getWorldMap() const
{
  return world_map_;
}

void AliveEntity::setPosition(QPointF position)
{
  position_ = position;
}

void AliveEntity::killMe()
{
  is_alive_ = false;
}

void AliveEntity::setAllowedBiomes(QVector<Biome> new_biomes)
{
  allowed_biomes_ = new_biomes;
}

QVector<Biome> AliveEntity::getAllowedBiomes()
{
  return allowed_biomes_;
}

bool AliveEntity::isPointReachable(QPointF point)
{
  return allowed_biomes_.contains(getWorldMap()->biomeAtPixel(point));
}

bool AliveEntity::isAdult() const
{
  return (age_ > 0.3 * max_age_ && age_ < 0.7 * max_age_);
}

int AliveEntity::getMaxAge() const
{
  return max_age_;
}

int AliveEntity::getSaturation() const
{
  return saturation_;
}

int AliveEntity::getMaxSaturation() const
{
  return max_saturation_;
}
}
