#ifndef ANIHILATION_H
#define ANIHILATION_H

#include "disaster.h"
#include "entity.h"

namespace WDWE::logic::disasters
{
class Anihilation : public Disaster
{
public:
  Anihilation(WorldMap *world_map);
  ~Anihilation();
  void tick() override;

private:
  entities::Kind target_;
  void killWholeKind();
};
}
#endif // ANIHILATION_H
