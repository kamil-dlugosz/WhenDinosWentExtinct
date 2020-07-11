#ifndef ENTITY_H
#define ENTITY_H

#include <QVector>
#include <QPointF>
#include "enum-kind.h"
#include "enum-biome.h"

namespace WDWE::logic
{
class WorldMap;

namespace entities
{
class AliveEntity
{  
public:
  AliveEntity(WorldMap *world_map, Kind getKind);
  virtual ~AliveEntity();
  virtual void tick();
  virtual int eatMe() = 0;
  Kind getKind() const;
  QPointF getPosition() const;
  int getAge() const;
  int getFertility() const;
  bool isAlive() const;
  bool isFertile();

protected:
  WorldMap *getWorldMap() const;
  void setPosition(QPointF position);
  void killMe();
  void setAllowedBiomes(QVector<Biome> new_biomes);
  QVector<Biome> getAllowedBiomes();
  bool isPointReachable(QPointF point);
  bool isAdult() const;
  bool incAge(int value = 1);
  bool incFertility(int value = 1);
  void incSaturation(int value = 1);
  void resetFertility();
  void setSaturation(int value = 0);
  int getMaxAge() const;
  int getSaturation() const;
  int getMaxSaturation() const;

private:
  WorldMap *const world_map_;
  const Kind kind_;
  const float max_age_;
  const int max_fertility_;
  const int max_saturation_;
  float age_;
  int fertility_;
  int saturation_;
  QPointF position_;
  QVector<Biome> allowed_biomes_;
  bool is_alive_;
};
}}
#endif // ENTITY_H
