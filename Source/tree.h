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

protected:
  int max_leaves_;
  int leaves_number_;
  int nutrients_per_leaf_;
  int max_fruits_;
  int fruits_number_;
  int nutrients_per_fruit_;

  void spread() override;
  void grow() override;
};
}
#endif // TREE_H
