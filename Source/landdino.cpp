#include <QRandomGenerator>
#include "landdino.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
LandDino::LandDino(WorldMap *world_map, Kind kind)
  : Dino(world_map, kind)
{
  QVector<Biome> allowed_biomes(4);
  allowed_biomes[0] = Biome::SAND;
  allowed_biomes[1] = Biome::SAVANNA;
  allowed_biomes[2] = Biome::FOREST;
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
  QVector<Kind> diet(3);
  diet[0] = Kind::AIRDINO;
  diet[1] = Kind::GRASS;
  diet[2] = Kind::BUSH;
  setDiet(diet);
}

LandDino::~LandDino()
{

}

void LandDino::tick()
{
  Dino::tick();
}

AliveEntity *LandDino::findFood()
{
  return Dino::findFood();
}

AliveEntity *LandDino::findMate()
{
  LandDino *closest_mate = nullptr;
  float closest_mate_dist = getMaxViewDist();
  for (int mate_index = 0; mate_index < getWorldMap()->entityNumber(); ++ mate_index) {
    LandDino *potencial_mate =
        dynamic_cast<LandDino*>(getWorldMap()->entityAt(mate_index));
    if (potencial_mate == nullptr ||
        potencial_mate == this ||
        potencial_mate->isAlive() == false ||
        potencial_mate->getKind() != this->getKind() ||
        potencial_mate->getSex() == this->getSex() ||
        potencial_mate->getMate() != nullptr ||
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

void LandDino::eat(AliveEntity *prey)
{
  Dino::eat(prey);
}

void LandDino::mating()
{
  if (getMate() != nullptr) {
    float distance = (getPosition() - getMate()->getPosition()).manhattanLength();
    if (distance < getMinViewDist()) {
      LandDino *mate = dynamic_cast<LandDino*>(getMate());
      if (mate) {
        int children_number = QRandomGenerator::system()->bounded(1, 3);
        for (int i = 0; i < children_number; ++ i)
          getWorldMap()->entityAdd(getKind());
        mate->unpair();
        resetFertility();
        mate->resetFertility();
      }}}
}

void LandDino::pair(AliveEntity *new_mate)
{
  if (new_mate != nullptr) {
    LandDino *mate = dynamic_cast<LandDino*>(new_mate);
    if (mate != nullptr){
      mate->setMate(this);
      this->setMate(mate);
    }}
}

void LandDino::unpair()
{
  LandDino *mate = dynamic_cast<LandDino*>(getMate());
  if (mate != nullptr)
    if (mate->getMate() == this)
      mate->setMate(nullptr);
  this->setMate(nullptr);
}

bool LandDino::move(QPointF destination)
{
  return Dino::move(destination);
}
}
