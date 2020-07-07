#ifndef BUSH_H
#define BUSH_H

#include "tree.h"

namespace WDWE::logic::entities
{
class Bush : public Tree
{
public:
  Bush(WorldMap *world_map, Kind getKind = Kind::BUSH);
  ~Bush();
  void tick() override;
  int eatMe() override;

public:
  void spread() override;
  void grow() override;
};
}
#endif // BUSH_H
