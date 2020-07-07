#include "tree.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Tree::Tree(WorldMap *world_map, Kind kind)
  : Plant(world_map, kind)
{

}

Tree::~Tree()
{

}

void Tree::tick()
{

}

int Tree::eatMe()
{
  return Plant::eatMe();
}

void Tree::spread()
{

}

void Tree::grow()
{

}
}
