#ifndef ALGA_H
#define ALGA_H

#include "grass.h"

namespace WDWE::logic::entities
{
class Alga : public Grass
{
public:
  Alga(WorldMap *world_map, Kind getKind = Kind::ALGA);
  ~Alga();
  void tick() override;
  int eatMe() override;

private:
  void spread() override;
  void grow() override;
};
}
#endif // ALGA_H
