#include <QDebug>
#include "simulation.h"
#include "include-kinds.h"

namespace WDWE::logic
{
Simulation::Simulation()
{
  world_map_ = createWorld();
  timer_ = new QTimer(this);
  connect(timer_, SIGNAL(timeout()), this, SLOT(tick()));
  timer_->start(interval_);
  for (int i = 0; i < 2; ++ i)
    world_map_->entityAdd(entities::Kind::AIRDINO);
  for (int i = 0; i < 0; ++ i)
    world_map_->entityAdd(entities::Kind::LANDDINO);
  for (int i = 0; i < 0; ++ i)
    world_map_->entityAdd(entities::Kind::WATERDINO);
  for (int i = 0; i < 0; ++ i)
    world_map_->entityAdd(entities::Kind::ALGA);
  for (int i = 0; i < 0; ++ i)
    world_map_->entityAdd(entities::Kind::BUSH);
  for (int i = 0; i < 100; ++ i)
    world_map_->entityAdd(entities::Kind::GRASS);
  for (int i = 0; i < 0; ++ i)
    world_map_->entityAdd(entities::Kind::TREE);
}

Simulation::~Simulation()
{
  delete world_map_;
}

bool Simulation::entityAdd(entities::Entity *entity)
{
  return world_map_->entityAdd(entity);
}

bool Simulation::entityAdd(entities::Kind kind)
{
  return world_map_->entityAdd(kind);
}

bool Simulation::entityErase(int index)
{
  return world_map_->entityErase(index);
}

bool Simulation::entityErase(entities::Entity *entity)
{
  return world_map_->entityErase(entity);
}

int Simulation::eatMeAt(int index)
{
  return world_map_->eatMeAt(index);
}

entities::Kind Simulation::kindAt(int index) const
{
  return world_map_->kindAt(index);
}

QPointF Simulation::positionAt(int index) const
{
  return world_map_->positionAt(index);
}

int Simulation::entityNumber() const
{
  return world_map_->entityNumber();
}

Biome Simulation::biomeAt(int x, int y) const
{
  return world_map_->biomeAt(x, y);
}

bool Simulation::biomeChange(Biome biome, int x, int y)
{
  return world_map_->biomeChange(biome, x, y);
}

int Simulation::pixelWidth() const
{
  return world_map_->pixelWidth();
}

int Simulation::pixelHeight() const
{
  return world_map_->pixelHeight();
}

int Simulation::tileWidth() const
{
  return world_map_->tileWidth();
}

int Simulation::tileHeight() const
{
  return world_map_->tileHeight();
}

WorldMap *Simulation::createWorld()
{
  return new WorldMap;
}

void Simulation::tick()
{
  world_map_->tick();
}
}
