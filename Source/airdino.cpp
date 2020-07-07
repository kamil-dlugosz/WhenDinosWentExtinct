#include <QDebug>
#include <QRandomGenerator>
#include "airdino.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
AirDino::AirDino(WorldMap *world_map, Kind kind)
  : Dino(world_map, kind)
{

}

AirDino::~AirDino()
{

}

void AirDino::tick()
{
  Dino::tick();
}

Entity *AirDino::findFood()
{
  return Dino::findFood();
}

Entity *AirDino::findMate()
{
  AirDino *closest_mate = nullptr;
  float closest_mate_dist = getMaxViewDist();
  for (int mate_index = 0; mate_index < worldMap()->entityNumber(); ++ mate_index) {
    AirDino *potencial_mate =
        dynamic_cast<AirDino*>(worldMap()->entityAt(mate_index));
    if (potencial_mate == nullptr ||
        potencial_mate == this ||
        potencial_mate->getKind() != this->getKind() ||
        potencial_mate->sex() == this->sex() ||
        potencial_mate->isReadyToMate() == false)
      continue;
    float current_distance
        = (potencial_mate->getPosition() - this->getPosition()).manhattanLength();
    if (current_distance < closest_mate_dist) {
      closest_mate_dist = current_distance;
      closest_mate = potencial_mate;
    }}
  return closest_mate;
}

void AirDino::eat()
{
  Dino::eat();
}

void AirDino::mating()
{
  if (getTarget() != nullptr) {
    float distance = (getPosition() - getTarget()->getPosition()).manhattanLength();
    if (distance < getMinViewDist()) {
      AirDino *mate = dynamic_cast<AirDino*>(getTarget());
      if (mate) {
        int children_number = QRandomGenerator::system()->bounded(1, 3);
        for (int i = 0; i < children_number; ++ i)
          worldMap()->entityAdd(getKind());
        mate->unpair();
        resetFertility();
        mate->resetFertility();
      }}}
}

void AirDino::pair(Entity *target)
{
  if (target != nullptr) {
    AirDino *mate = dynamic_cast<AirDino*>(target);
    if (mate != nullptr){
      mate->setTarget(this);
      this->setTarget(mate);
    }}
}

void AirDino::unpair()
{
  AirDino *mate = dynamic_cast<AirDino*>(getTarget());
  if (mate != nullptr)
    if (mate->getTarget() == this)
      mate->setTarget(nullptr);
  this->setTarget(nullptr);
}

bool AirDino::move()
{
  return Dino::move();
}
}
