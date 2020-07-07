#ifndef PLANT_H
#define PLANT_H

#include "entity.h"

namespace WDWE::logic::entities
{
class Plant : public Entity
{
public:
  Plant(WorldMap *world_map, Kind getKind);
  virtual ~Plant();
  virtual void tick() override;
  virtual int eatMe() override;

protected:
  int spread_rate_;

  virtual void spread() = 0;
  virtual void grow() = 0;
};
}
#endif // PLANT_H
