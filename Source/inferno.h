#ifndef INFERNO_H
#define INFERNO_H

#include <QPoint>
#include "disaster.h"

namespace WDWE::logic::disasters
{
class Inferno : public Disaster
{
public:
  Inferno(WorldMap *world_map, Type type = Type::INFERNO);
  virtual ~Inferno();
  void tick() override;

protected:
  QPointF getCenter();
  int getSpreadPace();
  void destroySoil();
  void spreadFire();

private:
  QPointF center_;
  int spread_pace_;
};
}
#endif // INFERNO_H
