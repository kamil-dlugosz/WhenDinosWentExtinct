#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QTimer>
#include "worldmap.h"
#include "disaster.h"
#include "enum-biome.h"
#include "enum-kind.h"

namespace WDWE::logic
{
class Simulation : public QObject
{
  Q_OBJECT
public:
  Simulation();
  ~Simulation();
  void simPause();
  void simStart();
  void simFaster();
  void simSlower();
  void simResetSpeed();
//  bool entityAdd(entities::AliveEntity* entity);
  bool entityAdd(entities::Kind kind);
  bool startDisaster(disasters::Type type);
//  bool entityErase(int index);
//  bool entityErase(entities::AliveEntity* entity);
//  int eatMeAt(int index);
  entities::Kind kindAt(int index) const;
  QPointF positionAt(int index) const;
  int entityNumber() const;
  Biome biomeAt(int x, int y) const;
//  bool biomeChange(Biome biome, int x, int y);
  bool getDisasterType() const;
  int pixelWidth() const;
  int pixelHeight() const;
  int tileWidth() const;
  int tileHeight() const;

private:
  QTimer *timer_;
  disasters::Disaster *disaster_;
  WorldMap *world_map_;
  float default_interval_;
  float interval_;

  WorldMap *createWorld();

private slots:
  void tick();
};
}
#endif // SIMULATION_H
