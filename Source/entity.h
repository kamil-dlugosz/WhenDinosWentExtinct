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
  AliveEntity(WorldMap *world_map, Kind getKind, QPointF position = QPointF(0, 0));
  virtual ~AliveEntity();
  virtual void tick();
  virtual int eatMe() = 0;
  Kind getKind() const;
  QPointF getPosition() const;
  int getAge() const;
  int getFertility() const;
  bool isAlive();
  bool isFertile();
  void incHealth(int value = 1);

protected:
  WorldMap *getWorldMap() const;
  void setPosition(QPointF position);
  void killMe();
  void setAllowedBiomes(QVector<Biome> new_biomes);
  QVector<Biome> getAllowedBiomes();
  bool isInGoodBiome(QPointF point);
  virtual bool isAdult() const;
  bool incAge(int value = 1);
  bool incFertility(int value = 1);
  void incSaturation(int value = 1);
  void resetFertility();
  void setSaturation(int value = 0);
  void setMaxFertility(int value);
  int getMaxHealth() const;
  int getMaxAge() const;
  int getSaturation() const;
  int getMaxSaturation() const;
  int getHealth() const;

private:
  WorldMap *const world_map_;
  const Kind kind_;
  int max_health_;
  float max_age_;
  int max_fertility_;
  int max_saturation_;
  int health_;
  float age_;
  int fertility_;
  int saturation_;
  QPointF position_;
  QVector<Biome> allowed_biomes_;
  bool is_alive_;
};
}}
#endif // ENTITY_H
