#ifndef GRASS_H
#define GRASS_H

#include "plant.h"

namespace WDWE::logic::entities
{
class Grass : public Plant
{
public:
  Grass(WorldMap *world_map, Kind getKind = Kind::GRASS);
  virtual ~Grass();
  void tick() override;
  int eatMe() override;

protected:
  int lenght_;
  int max_lenght_;
  int nutrient_per_piece_;

  void spread() override;
  void grow() override;
};
}
#endif // GRASS_H
