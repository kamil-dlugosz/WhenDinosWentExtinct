#include <QDebug>
#include "meteor.h"

namespace WDWE::logic::disasters
{
Meteor::Meteor(WorldMap *world_map, int duration, int max_size, float spread_pace)
  : Inferno(world_map, duration, max_size, spread_pace, Type::METEOR)
{
  meteorFall();
  incSize(getMaxSize() * 0.3);
}

Meteor::~Meteor()
{

}

void Meteor::tick()
{
  Inferno::tick();
}

void Meteor::meteorFall()
{
  int ratio = getWorldMap()->tileSize();
  for (int x = 0; x < getWorldMap()->tileWidth(); ++ x)
    for (int y = 0; y < getWorldMap()->tileHeight(); ++ y) {
      float current_distance
          = (QPointF(x * ratio, y * ratio) - getCenter()).manhattanLength();
      if (current_distance < getMaxSize() * 0.3 &&
          (getWorldMap()->biomeAtTile(x, y) != Biome::WATER ||
           getWorldMap()->biomeAtTile(x, y) != Biome::DEEPWATER))
        getWorldMap()->biomeChange(Biome::STONE, x, y, false);
    }
}
}
