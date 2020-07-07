#include <QtMath>
#include <QRandomGenerator>
#include <QDebug>
#include "dino.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Dino::Dino(WorldMap *world_map, Kind kind)
  : Entity(world_map, kind)
  , max_saturation_ (4000)
  , hgh_saturation_ (3000)
  , low_saturation_ (2000)
  , min_view_dist_ (5)
  , max_view_dist_ (6000)
  , max_fertility_(40)
  , max_age_ (15000)
  , sex_ ((int)getPosition().x() % 2 == 0 ? Sex::FEMALE : Sex::MALE)
  , diet_ (Kind::GRASS)
  , satutation_ (1750)
  , fertility_ (0)
  , speed_ (60)
  , age_ (0)
  , target_ (nullptr)
{

}

Dino::~Dino()
{
  unpair();
}

void Dino::tick()
{
  if (age_ >= max_age_ || satutation_ <= 0 || !isAlive()) {
    killMe();
    return;
  }
  if (isHungry()) {
    unpair();
    setTarget(findFood());
  }
  else if (getTarget() == nullptr && isAdult()) {
    fertility_ += QRandomGenerator::system()->bounded(5);
    if (isFertile()) {
      pair(findMate());
    }
  }
  eat();
  mating();
  move();
  age_ += 1;
  satutation_ -= QRandomGenerator::system()->bounded(5);
}

int Dino::eatMe()
{
  killMe();
  return 0;
}

Entity *Dino::getTarget() const
{
  return target_;
}

bool Dino::isReadyToMate()
{
  if (isAlive() && isFed() && isFertile() && isAdult() && getTarget() == nullptr)
    return true;
  else
    return false;
}

bool Dino::isFertile()
{
  return (fertility_ >= max_fertility_);
}

void Dino::resetFertility()
{
  fertility_ = 0;
}

bool Dino::isHungry() const
{
  return (satutation_ < hgh_saturation_);
}

bool Dino::isFed() const
{
  return (satutation_ > low_saturation_);
}

bool Dino::isAdult() const
{
  return (age_ > 0.1 * max_age_ && age_ < 0.7 * max_age_);
}

bool Dino::isYummy(Kind food) const
{
  return food == diet_;
}

int Dino::getMinViewDist() const
{
  return min_view_dist_;
}

int Dino::getMaxViewDist() const
{
  return max_view_dist_;
}

void Dino::setTarget(Entity *new_target)
{
  target_ = new_target;
}

Entity *Dino::findFood()
{
  Entity *closest_food = nullptr;
  float closest_food_dist = getMaxViewDist();
  for (int food_index = 0; food_index < worldMap()->entityNumber(); ++ food_index) {
    if (worldMap()->entityAt(food_index) == this ||
        !isYummy(worldMap()->kindAt(food_index)))
      continue;
    float current_distance
        = (worldMap()->positionAt(food_index) - getPosition()).manhattanLength();
    if (current_distance < closest_food_dist) {
      closest_food_dist = current_distance;
      closest_food = worldMap()->entityAt(food_index);
    }}
  return closest_food;
}

void Dino::eat()
{
  if (getTarget() != nullptr) {
    float distance = (getPosition() - getTarget()->getPosition()).manhattanLength();
    if (distance < getMinViewDist() && getTarget()->getKind() != getKind()) {
      satutation_ += getTarget()->eatMe();
      setTarget(nullptr);
      if (satutation_ > max_saturation_)
        satutation_ = max_saturation_;
    }}
}

void Dino::unpair()
{

}

//bool Dino::wander(QPointF &destination)
//{
//  if ((position_ - destination_).manhattanLength() > 100)
//    return false;
//  destination.rx() += (QRandomGenerator::system()->bounded(0, 400) - 200);
//  destination.ry() += (QRandomGenerator::system()->bounded(0, 400) - 200);
//  return true;
//}

bool Dino::move()
{
  if (target_ == nullptr)
    return false;
  QPointF new_position;
  QPointF offset;
  offset = target_->getPosition() - this->getPosition();
  float dist = qSqrt(offset.x()*offset.x() + offset.y()*offset.y());
  offset.rx() *= speed_ / 100.0 / dist;
  offset.ry() *= speed_ / 100.0 / dist;
  new_position = getPosition() += offset;
  setPosition(new_position);
  return true;
}

Dino::Sex Dino::sex() const
{
  return sex_;
}
}
