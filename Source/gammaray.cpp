#include <QRandomGenerator>
#include "gammaray.h"

namespace WDWE::logic::disasters
{
GammaRay::GammaRay(WorldMap *world_map, int duration, int hp_decrease)
  : Disaster(world_map, duration, Type::GAMMARAY)
  , hp_decrease_(hp_decrease)
{

}

GammaRay::~GammaRay()
{

}

void GammaRay::tick()
{
  Disaster::tick();
  damageDinos();
}

void GammaRay::damageDinos()
{
  for (int i = 0; i < getWorldMap()->entityNumber(); ++ i) {
    if (getWorldMap()->kindAt(i) != entities::Kind::AIRDINO &&
        getWorldMap()->kindAt(i) != entities::Kind::LANDDINO)
      continue;
    if (10 > QRandomGenerator::system()->bounded(100))
      getWorldMap()->entityAt(i)->incHealth(-hp_decrease_);
  }
}
}
