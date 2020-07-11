#include <QDebug>
#include "simulation.h"
#include "include-entities.h"
#include "include-disasters.h"

namespace WDWE::logic
{
Simulation::Simulation()
  : timer_(new QTimer(this))
  , disaster_(nullptr)
  , world_map_(createWorld())
  , default_interval_(1000.0/60.0)
  , interval_(default_interval_)
{
  connect(timer_, SIGNAL(timeout()), this, SLOT(tick()));
  timer_->start(interval_);
  for (int i = 0; i < 0; ++ i)
    world_map_->entityAdd(entities::Kind::AIRDINO);
  for (int i = 0; i < 1; ++ i)
    world_map_->entityAdd(entities::Kind::LANDDINO);
  for (int i = 0; i < 0; ++ i)
    world_map_->entityAdd(entities::Kind::WATERDINO);
  for (int i = 0; i < 10; ++ i)
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

void Simulation::simPause()
{
  timer_->stop();
}

void Simulation::simStart()
{
  timer_->start();
}

void Simulation::simFaster()
{
  interval_ /= 2;
  timer_->setInterval(interval_);
}

void Simulation::simSlower()
{
  interval_ *= 2;
  timer_->setInterval(interval_);
}

void Simulation::simResetSpeed()
{
  timer_->setInterval(default_interval_);
}

//bool Simulation::entityAdd(entities::AliveEntity *entity)
//{
//  return world_map_->entityAdd(entity);
//}

bool Simulation::entityAdd(entities::Kind kind)
{
  return world_map_->entityAdd(kind);
}

bool Simulation::startDisaster(disasters::Type type)
{
  if (disaster_ != nullptr) {
    delete disaster_;
    disaster_ = nullptr;
  }
  switch (type) {
  case disasters::Type::INFERNO:
    disaster_ = new disasters::Inferno(world_map_);
    break;
  case disasters::Type::METEOR:
    disaster_ = new disasters::Meteor(world_map_);
    break;
  case disasters::Type::GAMMARAY:
    disaster_ = new disasters::GammaRay(world_map_);
    break;
  case disasters::Type::DROUGHT:
    disaster_ = new disasters::Drought(world_map_);
    break;
  case disasters::Type::ANIHILATION:
    disaster_ = new disasters::Anihilation(world_map_);
    break;
  default:
    return false;
  }
  return true;
}

//bool Simulation::entityErase(int index)
//{
//  return world_map_->entityErase(index);
//}

//bool Simulation::entityErase(entities::AliveEntity *entity)
//{
//  return world_map_->entityErase(entity);
//}

//int Simulation::eatMeAt(int index)
//{
//  return world_map_->eatMeAt(index);
//}

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
  return world_map_->biomeAtPixel(x, y);
}

bool Simulation::getDisasterType() const
{
  if (disaster_ == nullptr)
    return disasters::Type::INVALID;
  return disaster_->getType();
}

//bool Simulation::biomeChange(Biome biome, int x, int y)
//{
//  return world_map_->biomeChange(biome, x, y);
//}

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
  if (disaster_ != nullptr) {
    if (disaster_->hasEnded()) {
      delete disaster_;
      disaster_ = nullptr;
    }
    else
      disaster_->tick();
  }
}
}
