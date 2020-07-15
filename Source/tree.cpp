#include <QRandomGenerator>
#include "tree.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Tree::Tree(WorldMap *world_map, QPointF position, Kind kind)
  : Plant(world_map, position, kind)
  , max_leaves_number_(15)
  , leaves_number_(7)
  , nutrients_per_leaf_(200)
  , max_fruits_number_(5)
  , fruits_number_(2)
  , nutrients_per_fruit_(500)
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
    if (isInGoodBiome(getPosition()))
      break;
    if (i ++ > max)
      killMe();
  }
  setMaxFertility(10000);
}

Tree::~Tree()
{

}

void Tree::tick()
{
  Plant::tick();
}

int Tree::eatMe()
{
  if (getFruitsNumber() > 0) {
    incFruits(-1);
    return getNutrientsPerFruit();
  }
  else if (getLeavesNumber() > 0) {
    incLeaves(-1);
    return getNutrientsPerLeaf();
  }
  else {
    killMe();
    return 0;
  }
}

void Tree::spread()
{
  Plant::spread();
}

void Tree::grow()
{
  if (isSaturated()) {
    if (incLeaves())
      incSaturation();
    else if (incFruits())
      incSaturation();
  }
  incSaturation(getGrowthRate());
}

bool Tree::incLeaves(int value)
{
  leaves_number_ += value;
  if (leaves_number_ > max_leaves_number_) {
    leaves_number_ = max_leaves_number_;
    return false;
  }
  return true;
}

bool Tree::incFruits(int value)
{
  fruits_number_ += value;
  if (fruits_number_ >= max_fruits_number_) {
    fruits_number_ = max_fruits_number_;
    return false;
  }
  return true;
}

int Tree::getMaxLeaves() const
{
  return max_leaves_number_;
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
