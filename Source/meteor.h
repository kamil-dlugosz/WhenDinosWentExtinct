#ifndef METEOR_H
#define METEOR_H

#include "inferno.h"

namespace WDWE::logic::disasters
{
class Meteor : public Inferno
{
public:
  explicit Meteor(WorldMap *world_map, int duration, int max_size, float spread_pace);
  virtual ~Meteor();
  void tick() override;

private:
  int explosion_radius_;

  void meteorFall();
};
}
#endif // METEOR_H
