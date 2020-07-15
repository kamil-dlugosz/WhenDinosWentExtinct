#ifndef ALGA_H
#define ALGA_H

#include "grass.h"

namespace WDWE::logic::entities
{
class Alga : public Grass
{
public:
  Alga(WorldMap *world_map, QPointF position, Kind getKind = Kind::ALGA);
  virtual ~Alga();
  void tick() override;
  int eatMe() override;

private:
  void spread() override;
  void grow() override;
};
}
#endif // ALGA_H
