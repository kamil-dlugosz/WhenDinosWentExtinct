#ifndef BUSH_H
#define BUSH_H

#include "tree.h"

namespace WDWE::logic::entities
{
//! Klasa implementująca krzew.
class Bush : public Tree
{
public:
  //! Konstruktor.
  Bush(WorldMap *world_map, QPointF position, Kind getKind = Kind::BUSH);
  //! Destruktor.
  virtual ~Bush();
  //! Funkcja aktualizująca paramety roślin z każdym krokiem symulacji.
  //! Regeneruje życie, zarządza głodem, płodnością, rośnięciem.
  void tick() override;
  //! Funkcja reagująca na bycie zjadanym. Zwraca wartość odżywczą.
  int eatMe() override;

public:
  //! Funkcja rozpszestrzeniająca rośliny na planszy.
  void spread() override;
  //! Funkcja realizująca rośnięcie roślin.
  void grow() override;
};
}
#endif // BUSH_H
