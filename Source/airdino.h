#ifndef AIRDINO_H
#define AIRDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
class AirDino : public Dino
{
public:
  AirDino(WorldMap *world_map, Kind kind = Kind::AIRDINO);
  ~AirDino();
  void tick() override;

private:
  int max_wing_stamina_;
  int wing_stamina_;
  int flying_speed_;

  AliveEntity *findFood() override;
  AliveEntity *findMate() override;
  void eat(AliveEntity *prey) override;
  void mating() override;
  void pair(AliveEntity *new_mate) override;
  void unpair() override;
  bool move(QPointF destination) override;
};
}
#endif // AIRDINO_H
