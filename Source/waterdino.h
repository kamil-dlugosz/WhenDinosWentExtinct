#ifndef WATERDINO_H
#define WATERDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
class WaterDino : public Dino
{
public:
  WaterDino(WorldMap *world_map, QPointF position, Kind kind = Kind::WATERDINO);
  virtual ~WaterDino();
  void tick() override;

private:
  AliveEntity *findFood() override;
  AliveEntity *findMate() override;
  void eat(AliveEntity *prey) override;
  void mating() override;
  void pair(AliveEntity *new_mate) override;
  void unpair() override;
  bool move(QPointF destination) override;
};
}
#endif // WATERDINO_H
