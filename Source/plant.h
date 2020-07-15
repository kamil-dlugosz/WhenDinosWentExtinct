#ifndef PLANT_H
#define PLANT_H

#include "entity.h"

namespace WDWE::logic::entities
{
class Plant : public AliveEntity
{
public:
  Plant(WorldMap *world_map, QPointF position, Kind kind);
  virtual ~Plant();
  virtual void tick() override;
  virtual int eatMe() override = 0;

protected:
  bool isAdult() const override;
  bool isSaturated() const;
  int getSpreadRate() const;
  int getGrowthRate() const;
  int getSeedNumber() const;

  virtual void spread();
  virtual void grow() = 0;

private:
  int spread_rate_;
  int growth_rate_;
  int seed_number_;
};
}
#endif // PLANT_H
