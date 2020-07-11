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
  Disaster(WorldMap *world_map, Type type);
  virtual ~Disaster();
  virtual void tick();
  Type getType() const;
  bool hasEnded() const;

protected:
  WorldMap *getWorldMap() const;
  int getDurationTotal() const;
  int getDurationLeft() const;

private:
  WorldMap *const world_map_;
  const Type type_;
  const int duration_total_;
  int duration_left_;
};
}
#endif // DISASTER_H
