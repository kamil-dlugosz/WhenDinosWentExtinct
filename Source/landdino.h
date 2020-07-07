#ifndef LANDDINO_H
#define LANDDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
class LandDino : public Dino
{
public:
  LandDino(WorldMap *world_map, Kind getKind = Kind::LANDDINO);
  ~LandDino();
  void tick() override;

private:
  int running_speed_;
  Entity *findFood() override;
  Entity *findMate() override;
  void eat() override;
  void mating() override;
  void pair(Entity *target) override;
  void unpair() override;
  bool move() override;
};
}
#endif // LANDDINO_H
