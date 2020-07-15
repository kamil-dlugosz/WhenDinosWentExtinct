#include <QDebug>
#include "simulation.h"
#include "include-entities.h"
#include "include-disasters.h"

namespace WDWE::logic
{
Simulation::Simulation()
  : timer_(new QTimer(this))
  , disaster_(nullptr)
  , world_map_(nullptr)
  , default_interval_(1000.0/60.0)
  , interval_(default_interval_)
{
  createNewWorld();
  connect(timer_, SIGNAL(timeout()), this, SLOT(tick()));
  timer_->start(interval_);
}

Simulation::~Simulation()
{
  delete world_map_;
}

void Simulation::createNewWorld()
{
  timer_->stop();
  if (world_map_ != nullptr)
    delete world_map_;
  world_map_ = new WorldMap();
  for (int i = 0; i < 20; ++ i)
    world_map_->entityAdd(entities::Kind::AIRDINO);
  for (int i = 0; i < 10; ++ i)
    world_map_->entityAdd(entities::Kind::LANDDINO);
  for (int i = 0; i < 10; ++ i)
    world_map_->entityAdd(entities::Kind::WATERDINO);
  for (int i = 0; i < 40; ++ i)
    world_map_->entityAdd(entities::Kind::ALGA);
  for (int i = 0; i < 70; ++ i)
    world_map_->entityAdd(entities::Kind::BUSH);
  for (int i = 0; i < 100; ++ i)
    world_map_->entityAdd(entities::Kind::GRASS);
  for (int i = 0; i < 50; ++ i)
    world_map_->entityAdd(entities::Kind::TREE);
  if (disaster_ != nullptr) {
    delete disaster_;
    disaster_ = nullptr;
  }
  timer_->start();
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

void Simulation::startInferno(int duration, int size, float fire_rate)
{
  if (disaster_ != nullptr) {
    delete disaster_;
    disaster_ = nullptr;
  }
  disaster_ = new disasters::Inferno(world_map_, duration, size, fire_rate);
}

void Simulation::startMeteor(int duration, int size, float fire_rate)
{
  if (disaster_ != nullptr) {
    delete disaster_;
    disaster_ = nullptr;
  }
  disaster_ = new disasters::Meteor(world_map_, duration, size, fire_rate);
}

void Simulation::startGammaRay(int duration, int rate)
{
  if (disaster_ != nullptr) {
    delete disaster_;
    disaster_ = nullptr;
  }
  disaster_ = new disasters::GammaRay(world_map_, duration, rate);
}

void Simulation::startDrought(int duration, float drying_rate)
{
  if (disaster_ != nullptr) {
    delete disaster_;
    disaster_ = nullptr;
  }
  disaster_ = new disasters::Drought(world_map_, duration, drying_rate);
}

void Simulation::startAnnihilation(entities::Kind target)
{
  if (disaster_ != nullptr) {
    delete disaster_;
    disaster_ = nullptr;
  }
  disaster_ = new disasters::Annihilation(world_map_, target);
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
