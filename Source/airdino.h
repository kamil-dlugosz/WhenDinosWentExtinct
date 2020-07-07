#ifndef AIRDINO_H
#define AIRDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
class AirDino : public Dino
{
public:
  AirDino(WorldMap *world_map, Kind getKind = Kind::AIRDINO);
  ~AirDino();
  void tick() override;

private:
  int max_wing_stamina_;
  int wing_stamina_;
  int flying_speed_;

  Entity *findFood() override;
  Entity *findMate() override;
  void eat() override;
  void mating() override;
  void pair(Entity *target) override;
  void unpair() override;
  bool move() override;
};
}
#endif // AIRDINO_H
