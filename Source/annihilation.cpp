#include <QDebug>
#include "annihilation.h"

namespace WDWE::logic::disasters
{
Annihilation::Annihilation(WorldMap *world_map, entities::Kind target)
  : Disaster(world_map, 0, Type::ANNIHILATION)
{
  killWholeKind(target);
  endDisaster();
}

Annihilation::~Annihilation()
{

}

void Annihilation::tick()
{

}

void Annihilation::killWholeKind(entities::Kind target)
{
  for (int i = 0; i < getWorldMap()->entityNumber(); ++ i)
    if (getWorldMap()->kindAt(i) == target)
      getWorldMap()->entityErase(i--);
}
}
