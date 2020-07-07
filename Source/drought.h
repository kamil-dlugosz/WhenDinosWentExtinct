#ifndef DROUGHT_H
#define DROUGHT_H

#include "disaster.h"

namespace WDWE::logic::disasters
{
class Drought : public Disaster
{
public:
  Drought(WorldMap *world_map);
  ~Drought();
  void tick() override;

private:
  int vaporize_rate_;

  void vaporizeWater();
};
}
#endif // DROUGHT_H
