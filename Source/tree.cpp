#include <QRandomGenerator>
#include "tree.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Tree::Tree(WorldMap *world_map, Kind kind)
  : Plant(world_map, kind)
{
  QVector<Biome> allowed_biomes(1);
  allowed_biomes[0] = Biome::FOREST;
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

Tree::~Tree()
{

}

void Tree::tick()
{

}

int Tree::eatMe()
{
  return Plant::eatMe();
}

void Tree::spread()
{

}

void Tree::grow()
{

}

int Tree::getMaxLeaves() const
{
  return max_leaves_;
}

int Tree::getLeavesNumber() const
{
  return leaves_number_;
}

int Tree::getNutrientsPerLeaf() const
{
  return nutrients_per_leaf_;
}

int Tree::getMaxFruitsNumber() const
{
  return max_fruits_number_;
}

int Tree::getFruitsNumber() const
{
  return fruits_number_;
}

int Tree::getNutrientsPerFruit() const
{
  return nutrients_per_fruit_;
}
}
