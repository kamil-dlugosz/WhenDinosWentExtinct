#ifndef PLANT_H
#define PLANT_H

#include "entity.h"

namespace WDWE::logic::entities
{
class Plant : public AliveEntity
{
public:
  Plant(WorldMap *world_map, Kind kind);
  virtual ~Plant();
  virtual void tick() override;
  virtual int eatMe() override = 0;

protected:
  int getSpreadRate() const;
  int getGrowthRate() const;
  int getSeedNumber() const;

  virtual void spread() = 0;
  virtual void grow() = 0;

private:
  const int spread_rate_;
  const int growth_rate_;
  const int seed_number_;
};
}
#endif // PLANT_H
