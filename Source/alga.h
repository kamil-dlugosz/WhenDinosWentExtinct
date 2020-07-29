#ifndef ALGA_H
#define ALGA_H

#include "grass.h"

namespace WDWE::logic::entities
{
//! Klasa definiująca glony.
class Alga : public Grass
{
public:
  //! Konstruktor.
  Alga(WorldMap *world_map, QPointF position, Kind getKind = Kind::ALGA);
  //! Destruktor.
  virtual ~Alga();
  //! Regeneruje życie, zarządza głodem, płodnością, rośnięciem.
  void tick() override;

private:
  //! Funkcja rozpszestrzeniająca rośliny na planszy.
  void spread() override;
  //! Funkcja realizująca rośnięcie roślin.
  void grow() override;
};
}
#endif // ALGA_H
