#ifndef INFERNO_H
#define INFERNO_H

#include <QPoint>
#include "disaster.h"

namespace WDWE::logic::disasters
{
class Inferno : public Disaster
{
public:
  explicit Inferno(WorldMap *world_map, int duration, int max_size, float spread_pace,
          Type type = Type::INFERNO);
  virtual ~Inferno();
  void tick() override;

protected:
  QPointF getCenter();
  void setCenter(QPointF new_center);
  int getSpreadPace() const;
  int getSize() const;
  int getMaxSize() const;
  void destroySoil();
  void killEntities();
  void incSize(float value);

private:
  QPointF center_;
  float max_size_;
  float size_;
  float spread_pace_;
};
}
#endif // INFERNO_H
