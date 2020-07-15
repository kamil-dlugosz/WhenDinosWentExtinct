#ifndef ANIHILATION_H
#define ANIHILATION_H

#include "disaster.h"
#include "entity.h"
#include "enum-kind.h"

namespace WDWE::logic::disasters
{
class Annihilation : public Disaster
{
public:
  explicit Annihilation(WorldMap *world_map, entities::Kind target);
  virtual ~Annihilation();
  void tick() override;

private:
  entities::Kind target_;
  void killWholeKind(entities::Kind target);
};
}
#endif // ANIHILATION_H
