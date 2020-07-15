#ifndef DISASTER_H
#define DISASTER_H

#include "worldmap.h"
#include "enum-type.h"

namespace WDWE::logic::disasters
{
class Disaster
{  
public:
  explicit Disaster(WorldMap *world_map, int duration, Type type);
  virtual ~Disaster();
  virtual void tick();
  Type getType() const;
  bool hasEnded() const;

protected:
  WorldMap *getWorldMap() const;
  int getDurationTotal() const;
  int getDurationLeft() const;
  void endDisaster();

private:
  WorldMap *const world_map_;
  const Type type_;
  const int duration_total_;
  int duration_left_;
};
}
#endif // DISASTER_H
