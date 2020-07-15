#include <QtMath>
#include <QRandomGenerator>
#include <QDebug>
#include "dino.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Dino::Dino(WorldMap *world_map, QPointF position, Kind kind)
  : AliveEntity(world_map, kind, position)
  , hgh_saturation_(3000)
  , low_saturation_(2000)
  , min_view_dist_(5)
  , max_view_dist_(1000)
  , sex_(QRandomGenerator::system()
         ->bounded(2) == 0 ? Sex::FEMALE : Sex::MALE)
  , speed_(60)
  , mate_(nullptr)
{

}

Dino::~Dino()
{
  //  unpair();
}

void Dino::tick()
{
  if (!isAlive()) {
    return;
  }
  if (isReadyToMate()) {
    if (getMate() == nullptr)
      pair(findMate());
    if (getMate() != nullptr) {
      move(mate_->getPosition());
      mating();
    }}
  else if (isHungry()) {
    AliveEntity *prey = nullptr;
    prey = findFood();
    if (prey != nullptr)
      eat(prey);
    if (prey != nullptr)
      move(prey->getPosition());
  }
  if (!isInGoodBiome(getPosition()) || isStarving()) {
    incHealth(-1);
  }
  else if (isInGoodBiome(getPosition()) && isFed()) {
    incHealth();
    incSaturation(-QRandomGenerator::system()->bounded(5));
  }
  incAge();
  incFertility(QRandomGenerator::system()->bounded(5));
  incSaturation(-QRandomGenerator::system()->bounded(5));
}

int Dino::eatMe()
{
  killMe();
  return 3000;
}

Dino *Dino::getMate() const
{
  return mate_;
}

bool Dino::isReadyToMate()
{
  return (isFed() && isFertile() && isAdult());
}

void Dino::setDiet(QVector<Kind> new_diet)
{
  diet_ = new_diet;
}

QVector<Kind> Dino::getDiet()
{
  return diet_;
}

bool Dino::isStarving() const
{
  return getSaturation() < 0;
}

bool Dino::isHungry() const
{
  return (getSaturation() < getHghSaturation());
}

bool Dino::isFed() const
{
  return (getSaturation() > getLowSaturation());
}

bool Dino::isYummy(Kind food) const
{
  return diet_.contains(food);
}

int Dino::getHghSaturation() const
{
  return hgh_saturation_;
}

int Dino::getLowSaturation() const
{
  return low_saturation_;
}

int Dino::getMinViewDist() const
{
  return min_view_dist_;
}

int Dino::getMaxViewDist() const
{
  return max_view_dist_;
}

void Dino::setMate(Dino *new_mate)
{
  mate_ = new_mate;
}

AliveEntity *Dino::findFood()
{
  AliveEntity *closest_food = nullptr;
  float closest_food_dist = getMaxViewDist();
  for (int food_index = 0; food_index < getWorldMap()->entityNumber(); ++ food_index) {
    if (getWorldMap()->entityAt(food_index) == this ||
        !isYummy(getWorldMap()->kindAt(food_index)) ||
        !isInGoodBiome(getWorldMap()->positionAt(food_index)))
      continue;
    float current_distance
        = (getWorldMap()->positionAt(food_index) - getPosition()).manhattanLength();
    if (current_distance < closest_food_dist) {
      closest_food_dist = current_distance;
      closest_food = getWorldMap()->entityAt(food_index);
    }}
  return closest_food;
}

void Dino::eat(AliveEntity *prey)
{
  if (prey != nullptr) {
    float distance = (getPosition() - prey->getPosition()).manhattanLength();
    if (distance < getMinViewDist() && prey->getKind() != getKind()) {
      incSaturation(prey->eatMe());
      prey = nullptr;
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

bool Dino::move(QPointF destination)
{
  QPointF offset;
  offset = destination - this->getPosition();
  float dist = qSqrt(offset.x()*offset.x() + offset.y()*offset.y());
  offset.rx() *= speed_ / 100.0 / dist;
  offset.ry() *= speed_ / 100.0 / dist;
  destination = getPosition() += offset;
  setPosition(destination);
  return true;
}

Dino::Sex Dino::getSex() const
{
  return sex_;
}
}
