#ifndef RESOURCES_H
#define RESOURCES_H

#include <QPixmap>
#include "enum-kind.h"
#include "enum-biome.h"

namespace WDWE::gui
{
class Resources
{
public:
  Resources();
  ~Resources();
  QPixmap *entityTexture(logic::entities::Kind kind) const;
  QPixmap *biomeTexture(logic::Biome biome) const;
private:
  QPixmap **entity_textures_;
  QPixmap **biome_textures_;
};
}
#endif // RESOURCES_H
