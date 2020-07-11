#ifndef LANDDINO_H
#define LANDDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
class LandDino : public Dino
{
public:
  LandDino(WorldMap *world_map, Kind kind = Kind::LANDDINO);
  ~LandDino();
  void tick() override;

private:
  int running_speed_;
  AliveEntity *findFood() override;
  AliveEntity *findMate() override;
  void eat(AliveEntity *prey) override;
  void mating() override;
  void pair(AliveEntity *new_mate) override;
  void unpair() override;
  bool move(QPointF destination) override;
};
}
#endif // LANDDINO_H
