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
  virtual ~Simulation();
  void createNewWorld();
  void simPause();
  void simStart();
  void simFaster();
  void simSlower();
  void simResetSpeed();
  void startInferno(int duration, int size, float fire_rate);
  void startMeteor(int duration, int size, float fire_rate);
  void startGammaRay(int duration, int rate);
  void startDrought(int duration, float drying_rate);
  void startAnnihilation(entities::Kind target);
  entities::Kind kindAt(int index) const;
  QPointF positionAt(int index) const;
  int entityNumber() const;
  Biome biomeAt(int x, int y) const;
  bool getDisasterType() const;
  int pixelWidth() const;
  int pixelHeight() const;
  int tileWidth() const;
  int tileHeight() const;

private:
  QTimer *timer_;
  disasters::Disaster *disaster_;
  WorldMap *world_map_;
  const float default_interval_;
  float interval_;

private slots:
  void tick();
};
}
#endif // SIMULATION_H
