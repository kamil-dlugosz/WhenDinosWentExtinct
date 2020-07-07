#ifndef DISASTER_H
#define DISASTER_H

#include "worldmap.h"

namespace WDWE::logic::disasters
{
enum Type {
  INVALID = 0,

  INFERNO,
  METEOR,
  GAMMARAY,
  DROUGHT,
  ANIHILATION,

  TOTAL
};
class Disaster
{  
public:
  Disaster(WorldMap *world_map);
  virtual ~Disaster();
  virtual void tick() = 0;
  Type type() { return type_; };

protected:
  WorldMap *world_map_;
  Type type_;
  int duration_total_;
  int duration_left_;
};
}
#endif // DISASTER_H
