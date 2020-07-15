#include <QRandomGenerator>
#include "plant.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Plant::Plant(WorldMap *world_map, QPointF position, Kind kind)
  : AliveEntity(world_map, kind, position)
  , spread_rate_(1)
  , growth_rate_(3)
  , seed_number_(3)
{
  setMaxFertility(1200);
}

Plant::~Plant()
{

}

void Plant::tick()
{
  if (!isAlive())
    return;
  if (isInGoodBiome(getPosition())) {
    incHealth();
    incSaturation(-1);
  }
  else
    incHealth(-1);
  spread();
  grow();
  incAge();
}

bool Plant::isAdult() const
{
  return (getAge() > 0.1 * getMaxAge() && getAge() < 0.9 * getMaxAge());
}

bool Plant::isSaturated() const
{
  return getSaturation() >= getMaxSaturation();
}

int Plant::eatMe()
{
  killMe();
  return 3000;
}

int Plant::getSpreadRate() const
{
  return spread_rate_;
}

int Plant::getGrowthRate() const
{
  return growth_rate_;
}

int Plant::getSeedNumber() const
{
  return seed_number_;
}

void Plant::spread()
{
  if (isFertile()) {
    for (int i = 0; i < getSeedNumber(); ++ i) {
      QPointF position = getPosition()
                         + QPointF(QRandomGenerator::system()->bounded(0, 100)-50,
                                   QRandomGenerator::system()->bounded(0, 100)-50);
      getWorldMap()->entityAdd(getKind(), position);
    }
    resetFertility();
  }
  incFertility(getSpreadRate());
}
}
