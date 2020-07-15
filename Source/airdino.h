#ifndef AIRDINO_H
#define AIRDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
class AirDino : public Dino
{
public:
  AirDino(WorldMap *world_map, QPointF position, Kind kind = Kind::AIRDINO);
  virtual ~AirDino();
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
#endif // AIRDINO_H
