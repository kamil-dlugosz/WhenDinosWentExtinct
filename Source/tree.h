#ifndef TREE_H
#define TREE_H

#include "plant.h"

namespace WDWE::logic::entities
{
class Tree : public Plant
{
public:
  Tree(WorldMap *world_map, Kind getKind = Kind::TREE);
  virtual ~Tree();
  void tick() override;
  int eatMe() override;

  int getMaxLeaves() const;
  int getLeavesNumber() const;
  int getNutrientsPerLeaf() const;
  int getMaxFruitsNumber() const;
  int getFruitsNumber() const;
  int getNutrientsPerFruit() const;

protected:
  void spread() override;
  void grow() override;

private:
  int max_leaves_;
  int leaves_number_;
  int nutrients_per_leaf_;
  int max_fruits_number_;
  int fruits_number_;
  int nutrients_per_fruit_;
};
}
#endif // TREE_H
