#ifndef WATERDINO_H
#define WATERDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
class WaterDino : public Dino
{
public:
  WaterDino(WorldMap *world_map, Kind getKind = Kind::WATERDINO);
  ~WaterDino();
  void tick() override;

private:
  int max_oxygen_;
  int oxygen_;

  Entity *findFood() override;
  Entity *findMate() override;
  void eat() override;
  void mating() override;
  void pair(Entity *target) override;
  void unpair() override;
  bool move() override;
  void takeABreath();
};
}
#endif // WATERDINO_H
