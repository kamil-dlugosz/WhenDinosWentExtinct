#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QTimer>
#include "worldmap.h"
#include "disaster.h"

namespace WDWE::logic
{
class Simulation : public QObject
{
  Q_OBJECT
public:
  Simulation();
  ~Simulation();
  bool entityAdd(entities::Entity* entity);
  bool entityAdd(entities::Kind kind);
  bool entityErase(int index);
  bool entityErase(entities::Entity* entity);
  int eatMeAt(int index);
  entities::Kind kindAt(int index) const;
  QPointF positionAt(int index) const;
  int entityNumber() const;
  Biome biomeAt(int x, int y) const;
  bool biomeChange(Biome biome, int x, int y);
  int pixelWidth() const;
  int pixelHeight() const;
  int tileWidth() const;
  int tileHeight() const;

private:
  QTimer *timer_;
  disasters::Disaster *disaster_;
  WorldMap *world_map_;
  float interval_ = 1000.0/60.0;

  WorldMap *createWorld();

private slots:
  void tick();
};
}
#endif // SIMULATION_H
