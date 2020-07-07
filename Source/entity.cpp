#include <QDebug>
#include <QRandomGenerator>
#include "entity.h"
#include "worldmap.h"

namespace WDWE::logic::entities
{
Entity::Entity(WorldMap *world_map, Kind kind)
  : world_map_(world_map)
  , position_(QPointF(QRandomGenerator::system()
                      ->bounded(quint32(0), quint32(world_map_->pixelWidth())),
                      QRandomGenerator::system()
                      ->bounded(quint32(0), quint32(world_map_->pixelHeight()))))
  , kind_(kind)
  , is_alive_(true)
{
  // czasami się wygeneruje kilka w jednym miejscu
//  position_.rx() *= world_map_->pixelWidth() / world_map_->tileWidth();
//  position_.ry() *= world_map_->pixelHeight() / world_map_->tileHeight();
}

Entity::~Entity()
{

}

void Entity::tick()
{

}

Kind Entity::getKind() const
{
  return kind_;
}

QPointF Entity::getPosition() const
{
  return position_;
}

bool Entity::isAlive() const
{
  return is_alive_;
}

WorldMap *Entity::worldMap() const
{
  return world_map_;
}

void Entity::setPosition(QPointF position)
{
  position_ = position;
}

void Entity::killMe()
{
  is_alive_ = false;
}
}
