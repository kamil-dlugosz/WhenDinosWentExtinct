#include "resources.h"
#include <QDebug>

namespace WDWE::gui
{
Resources::Resources()
{
  entity_textures_ = new QPixmap *[logic::entities::Kind::TOTAL];
  for (int i = 0; i < logic::entities::Kind::TOTAL; ++ i)
    entity_textures_[i] = new QPixmap(":/Textures/e" + QString::number(i) + ".png");

  biome_textures_ = new QPixmap *[logic::Biome::TOTAL];
  for (int i = 0; i < logic::Biome::TOTAL; ++ i)
    biome_textures_[i] = new QPixmap(":/Textures/b" + QString::number(i) + ".png");

  disaster_dialog_ = new QPixmap(":/Textures/disaster-dialog.jpg");
}

Resources::~Resources()
{
  delete disaster_dialog_;

  for (int i = 0; i < logic::Biome::TOTAL; ++ i)
    delete biome_textures_[i];
  delete[] biome_textures_;

  for (int i = 0; i < logic::entities::Kind::TOTAL; ++ i)
    delete entity_textures_[i];
  delete[] entity_textures_;
}

QPixmap Resources::entityTexture(logic::entities::Kind kind) const
{
  if (kind <= 0 || kind >= logic::entities::Kind::TOTAL)
    return *entity_textures_[logic::entities::Kind::INVALID];
  else
    return *entity_textures_[kind];
}

QPixmap Resources::biomeTexture(logic::Biome biome) const
{
  if (biome <= 0 || biome >= logic::Biome::TOTAL)
    return *biome_textures_[logic::Biome::INVALID];
  else
    return *biome_textures_[biome];
}

QPixmap Resources::disasterDialogTexture() const
{
  return *disaster_dialog_;
}
}
