#ifndef WATERDINO_H
#define WATERDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
class WaterDino : public Dino
{
public:
  WaterDino(WorldMap *world_map, Kind kind = Kind::WATERDINO);
  ~WaterDino();
  void tick() override;

private:
  int max_oxygen_;
  int oxygen_;

  AliveEntity *findFood() override;
  AliveEntity *findMate() override;
  void eat(AliveEntity *prey) override;
  void mating() override;
  void pair(AliveEntity *new_mate) override;
  void unpair() override;
  bool move(QPointF destination) override;
  void takeABreath();
};
}
#endif // WATERDINO_H
