#ifndef GAMMARAY_H
#define GAMMARAY_H

#include "disaster.h"

namespace WDWE::logic::disasters
{
class GammaRay : public Disaster
{
public:
  GammaRay(WorldMap *world_map);
  ~GammaRay();
  void tick() override;

private:
  int max_age_decrease_;
  int max_hp_decrease_;
  int hp_decrease_;

  void damageDinos();
};
}
#endif // GAMMARAY_H
