#ifndef ENTITY_H
#define ENTITY_H

#include <QPointF>
#include "enum-kind.h"

namespace WDWE::logic
{
class WorldMap;

namespace entities
{
class Entity
{  
public:
  Entity(WorldMap *world_map, Kind getKind);
  virtual ~Entity();
  virtual void tick();
  virtual int eatMe() = 0;
  Kind getKind() const;
  QPointF getPosition() const;
  bool isAlive() const;

protected:
  WorldMap *worldMap() const;
  void setPosition(QPointF position);
  void killMe();

private:
  WorldMap *const world_map_;
  QPointF position_;
  const Kind kind_;
  bool is_alive_;
};
}}
#endif // ENTITY_H
