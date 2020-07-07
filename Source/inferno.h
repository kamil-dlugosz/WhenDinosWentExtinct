#ifndef INFERNO_H
#define INFERNO_H

#include <QPoint>
#include "disaster.h"

namespace WDWE::logic::disasters
{
class Inferno : public Disaster
{
public:
  Inferno(WorldMap *world_map);
  virtual ~Inferno();
  void tick() override;

protected:
  QPointF center_;
  int spread_pace_;

  void destroySoil();
  void spreadFire();
};
}
#endif // INFERNO_H
