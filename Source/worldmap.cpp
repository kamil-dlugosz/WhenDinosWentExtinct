#include "worldmap.h"
#include "include-kinds.h"

namespace WDWE::logic
{
WorldMap::WorldMap()
{
  biome_width_ = 45;
  biome_height_ = 25;
  shift_ = 5;

  biome_grid_ = new Biome*[biome_width_];
  for(int x = 0; x < biome_width_; ++x) {
    biome_grid_[x] = new Biome[biome_height_];
    for (int y = 0; y < biome_height_; ++y) {
      if (x < 7)
        biome_grid_[x][y] = Biome::DEEPWATER;
      else if (x < 12)
        biome_grid_[x][y] = Biome::WATER;
      else if (x < 18)
        biome_grid_[x][y] = Biome::SAND;
      else if (x < 30)
        biome_grid_[x][y] = Biome::SAVANNA;
      else if (x > 35 && x < 45 && !(y < 6 || y > 12))
        biome_grid_[x][y] = Biome::STONE;
      else
        biome_grid_[x][y] = Biome::FOREST;
    }}
}

WorldMap::~WorldMap()
{
  qDeleteAll(entity_list_);
  entity_list_.clear();
  for (int x = 0; x < pixelWidth(); ++x)
    delete[] biome_grid_[x];
  delete[] biome_grid_;
}

void WorldMap::tick()
{
  for (int i = 0; i < entityNumber(); ++ i) {
    entity_list_[i]->tick();
    if (!entity_list_[i]->isAlive())
      entityErase(i);
  }
}

entities::Entity *WorldMap::entityAt(int index)
{
  return entity_list_[index];
}

bool WorldMap::entityAdd(entities::Entity *entity)
{
  if (entity == nullptr)
    return false;
  entity_list_.append(entity);
  return true;
}

bool WorldMap::entityAdd(entities::Kind kind)
{
  switch (kind) {
  case entities::Kind::AIRDINO:
    return entityAdd(new entities::AirDino(this));
  case entities::Kind::LANDDINO:
    return entityAdd(new entities::LandDino(this));
  case entities::Kind::WATERDINO:
    return entityAdd(new entities::WaterDino(this));
  case entities::Kind::ALGA:
    return entityAdd(new entities::Alga(this));
  case entities::Kind::BUSH:
    return entityAdd(new entities::Bush(this));
  case entities::Kind::GRASS:
    return entityAdd(new entities::Grass(this));
  case entities::Kind::TREE:
    return entityAdd(new entities::Tree(this));
  default:
    return false;
  }
}

bool WorldMap::entityErase(int index)
{
  if (index < 0 || index >= entityNumber())
    return false;
  delete entity_list_[index];
  entity_list_[index] = nullptr;
  entity_list_.removeAt(index);
  return true;
}

bool WorldMap::entityErase(entities::Entity *entity)
{
  return entity_list_.removeOne(entity);
}

int WorldMap::eatMeAt(int index)
{
  return entity_list_[index]->eatMe();
}

bool WorldMap::isAliveAt(int index) const
{
  return entity_list_[index]->isAlive();
}

entities::Kind WorldMap::kindAt(int index) const
{
  return entity_list_[index]->getKind();
}

QPointF WorldMap::positionAt(int index) const
{
  return entity_list_[index]->getPosition();
}

int WorldMap::entityNumber() const
{
  return entity_list_.size();
}

Biome WorldMap::biomeAt(int x, int y) const
{
  x = x >> shift_;
  y = y >> shift_;
  if (x < 0 || y < 0 || x >= biome_width_ || y >= biome_height_)
    return Biome::INVALID;
  return biome_grid_[x][y];
}

bool WorldMap::biomeChange(Biome biome, int x, int y)
{
  x = x >> shift_;
  y = y >> shift_;
  if (x < 0 || y < 0 || x >= biome_width_ || y >= biome_height_)
    return false;
  biome_grid_[x][y] = biome;
  return true;
}

int WorldMap::pixelWidth() const
{
  return biome_width_ << shift_;
}

int WorldMap::pixelHeight() const
{
  return biome_height_ << shift_;
}

int WorldMap::tileWidth() const
{
  return biome_width_;
}

int WorldMap::tileHeight() const
{
  return biome_height_;
}
}
