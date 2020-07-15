#ifndef DROUGHT_H
#define DROUGHT_H

#include "disaster.h"

namespace WDWE::logic::disasters
{
class Drought : public Disaster
{
public:
  explicit Drought(WorldMap *world_map, int duration, float drying_rate);
  virtual ~Drought();
  void tick() override;

protected:
  int getDryingRate() const;

private:
  float drying_rate_;

  void dryingBiomes();
  bool checkNeighbours(Biome biome, int x, int y);
};
}
#endif // DROUGHT_H
