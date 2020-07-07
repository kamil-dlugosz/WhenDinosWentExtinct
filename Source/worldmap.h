#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <QList>
#include "entity.h"
#include "enum-biome.h"

namespace WDWE::logic
{
class WorldMap
{
public:
  WorldMap();
  ~WorldMap();
  void tick();
  entities::Entity *entityAt(int index);
  bool entityAdd(entities::Entity* entity);
  bool entityAdd(entities::Kind kind);
  bool entityErase(int index);
  bool entityErase(entities::Entity* entity);
  int eatMeAt(int index);
  bool isAliveAt(int index) const;
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
  QList<entities::Entity*> entity_list_;
  Biome **biome_grid_;
  int biome_width_;
  int biome_height_;
  int shift_;
};
}
#endif // WORLDMAP_H
