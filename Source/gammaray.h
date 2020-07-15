#ifndef GAMMARAY_H
#define GAMMARAY_H

#include "disaster.h"

namespace WDWE::logic::disasters
{
class GammaRay : public Disaster
{
public:
  explicit GammaRay(WorldMap *world_map, int duration, int hp_decrease);
  virtual ~GammaRay();
  void tick() override;

private:
  int hp_decrease_;

  void damageDinos();
};
}
#endif // GAMMARAY_H
