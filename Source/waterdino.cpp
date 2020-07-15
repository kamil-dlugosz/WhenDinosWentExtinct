#include <QRandomGenerator>
#include "waterdino.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
WaterDino::WaterDino(WorldMap *world_map, QPointF position, Kind kind)
  : Dino(world_map, position, kind)
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
  QVector<Kind> diet(1);
  diet[0] = Kind::ALGA;
  setDiet(diet);
}

WaterDino::~WaterDino()
{

}

void WaterDino::tick()
{
  Dino::tick();
}

AliveEntity *WaterDino::findFood()
{
  return Dino::findFood();
}

AliveEntity *WaterDino::findMate()
{
  WaterDino *closest_mate = nullptr;
  float closest_mate_dist = getMaxViewDist();
  for (int mate_index = 0; mate_index < getWorldMap()->entityNumber(); ++ mate_index) {
    WaterDino *potencial_mate =
        dynamic_cast<WaterDino*>(getWorldMap()->entityAt(mate_index));
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

void WaterDino::eat(AliveEntity *prey)
{
  Dino::eat(prey);
}

void WaterDino::mating()
{
  if (getMate() != nullptr) {
    float distance = (getPosition() - getMate()->getPosition()).manhattanLength();
    if (distance < getMinViewDist()) {
      WaterDino *mate = dynamic_cast<WaterDino*>(getMate());
      if (mate) {
        int children_number = QRandomGenerator::system()->bounded(1, 3);
        for (int i = 0; i < children_number; ++ i)
          getWorldMap()->entityAdd(getKind());
        mate->unpair();
        resetFertility();
        mate->resetFertility();
      }}}
}

void WaterDino::pair(AliveEntity *new_mate)
{
  if (new_mate != nullptr) {
    WaterDino *mate = dynamic_cast<WaterDino*>(new_mate);
    if (mate != nullptr){
      mate->setMate(this);
      this->setMate(mate);
    }}
}

void WaterDino::unpair()
{
  WaterDino *mate = dynamic_cast<WaterDino*>(getMate());
  if (mate != nullptr)
    if (mate->getMate() == this)
      mate->setMate(nullptr);
  this->setMate(nullptr);
}

bool WaterDino::move(QPointF destination)
{
  return Dino::move(destination);
}
}
