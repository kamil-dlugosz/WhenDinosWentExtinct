#ifndef LANDDINO_H
#define LANDDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
class LandDino : public Dino
{
public:
  LandDino(WorldMap *world_map, QPointF position, Kind kind = Kind::LANDDINO);
  virtual ~LandDino();
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
#endif // LANDDINO_H
