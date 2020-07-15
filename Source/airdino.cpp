#include <QDebug>
#include <QRandomGenerator>
#include "airdino.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
AirDino::AirDino(WorldMap *world_map, QPointF position, Kind kind)
  : Dino(world_map, position, kind)
{
//  qDebug() << static_cast<int>(getSex());
  QVector<Biome> allowed_biomes(5);
  allowed_biomes[0] = Biome::SAND;
  allowed_biomes[1] = Biome::SAVANNA;
  allowed_biomes[2] = Biome::FOREST;
  allowed_biomes[3] = Biome::STONE;
  allowed_biomes[4] = Biome::WATER;
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
  QVector<Kind> diet(3);
  diet[0] = Kind::WATERDINO;
  diet[1] = Kind::TREE;
  diet[2] = Kind::BUSH;
  setDiet(diet);
}

AirDino::~AirDino()
{

}

void AirDino::tick()
{
  Dino::tick();
}

AliveEntity *AirDino::findFood()
{
  return Dino::findFood();
}

AliveEntity *AirDino::findMate()
{
  AirDino *closest_mate = nullptr;
  float closest_mate_dist = getMaxViewDist();
  for (int mate_index = 0; mate_index < getWorldMap()->entityNumber(); ++ mate_index) {
    AirDino *potencial_mate =
        dynamic_cast<AirDino*>(getWorldMap()->entityAt(mate_index));
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

void AirDino::eat(AliveEntity *prey)
{
  Dino::eat(prey);
}

void AirDino::mating()
{
  if (getMate() != nullptr) {
    float distance = (getPosition() - getMate()->getPosition()).manhattanLength();
    if (distance < getMinViewDist()) {
      AirDino *mate = dynamic_cast<AirDino*>(getMate());
      if (mate) {
        int children_number = QRandomGenerator::system()->bounded(1, 3);
        for (int i = 0; i < children_number; ++ i)
          getWorldMap()->entityAdd(getKind());
        mate->unpair();
        resetFertility();
        mate->resetFertility();
      }}}
}

void AirDino::pair(AliveEntity *new_mate)
{
  if (new_mate != nullptr) {
    AirDino *mate = dynamic_cast<AirDino*>(new_mate);
    if (mate != nullptr){
      mate->setMate(this);
      this->setMate(mate);
    }}
}

void AirDino::unpair()
{
  if (getMate() == nullptr)
    return;
  AirDino *mate = dynamic_cast<AirDino*>(getMate());
  if (mate != nullptr)
    if (mate->getMate() == this)
      mate->setMate(nullptr);
  this->setMate(nullptr);
}

bool AirDino::move(QPointF destination)
{
  return Dino::move(destination);
}
}
