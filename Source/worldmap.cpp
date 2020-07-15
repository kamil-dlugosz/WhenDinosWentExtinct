#include "worldmap.h"
#include "include-entities.h"

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
  for (int x = 0; x < tileWidth(); ++ x)
    delete[] biome_grid_[x];
  delete[] biome_grid_;
}

void WorldMap::tick()
{
  for (int i = 0; i < entityNumber(); ++ i)
    if (!entity_list_[i]->isAlive())
      entityErase(i);
  for (int i = 0; i < entityNumber(); ++ i)
    entity_list_[i]->tick();
}

entities::AliveEntity *WorldMap::entityAt(int index)
{
  return entity_list_[index];
}

bool WorldMap::entityAdd(entities::AliveEntity *entity)
{
  if (entity == nullptr)
    return false;
  entity_list_.append(entity);
  return true;
}

bool WorldMap::entityAdd(entities::Kind kind, QPointF position)
{
  switch (kind) {
  case entities::Kind::AIRDINO:
    return entityAdd(new entities::AirDino(this, position));
  case entities::Kind::LANDDINO:
    return entityAdd(new entities::LandDino(this, position));
  case entities::Kind::WATERDINO:
    return entityAdd(new entities::WaterDino(this, position));
  case entities::Kind::ALGA:
    return entityAdd(new entities::Alga(this, position));
  case entities::Kind::BUSH:
    return entityAdd(new entities::Bush(this, position));
  case entities::Kind::GRASS:
    return entityAdd(new entities::Grass(this, position));
  case entities::Kind::TREE:
    return entityAdd(new entities::Tree(this, position));
  default:
    return false;
  }
}

bool WorldMap::entityErase(int index)
{
  if (index < 0 || index >= entityNumber() || entity_list_[index] == nullptr)
    return false;
  delete entity_list_[index];
  entity_list_[index] = nullptr;
  entity_list_.removeAt(index);
  return true;
}

bool WorldMap::entityErase(entities::AliveEntity *entity)
{
  if (entity == nullptr)
    return false;
  delete entity;
  entity = nullptr;
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

Biome WorldMap::biomeAtPixel(int x, int y) const
{
  x = x >> shift_;
  y = y >> shift_;
  if (x < 0 || y < 0 || x >= biome_width_ || y >= biome_height_)
    return Biome::INVALID;
  return biome_grid_[x][y];
}

Biome WorldMap::biomeAtPixel(QPointF position) const
{
  QPoint pos = position.toPoint();
  pos.rx() = pos.x() >> shift_;
  pos.ry() = pos.y() >> shift_;
  if (pos.x() < 0 ||  pos.y() < 0 ||
      pos.x() >= biome_width_ ||  pos.y() >= biome_height_)
    return Biome::INVALID;
  return biome_grid_[pos.x()][ pos.y()];
}

Biome WorldMap::biomeAtTile(int x, int y) const
{
  if (x < 0 || y < 0 || x >= biome_width_ || y >= biome_height_)
    return Biome::INVALID;
  return biome_grid_[x][y];
}

Biome WorldMap::biomeAtTile(QPointF position) const
{
  QPoint pos = position.toPoint();
  if (pos.x() < 0 ||  pos.y() < 0 ||
      pos.x() >= biome_width_ ||  pos.y() >= biome_height_)
    return Biome::INVALID;
  return biome_grid_[pos.x()][ pos.y()];
}

bool WorldMap::biomeChange(Biome biome, int x, int y, bool tile)
{
  if (tile) {
    x = x >> shift_;
    y = y >> shift_;
  }
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

int WorldMap::tileSize() const
{
  return 1 << shift_;
}
}
