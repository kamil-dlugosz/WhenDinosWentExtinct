#ifndef LANDDINO_H
#define LANDDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
//! Klasa definiująca dinozaury lądowe.
class LandDino : public Dino
{
public:
  //! Konstruktor.
  LandDino(WorldMap *world_map, QPointF position, Kind kind = Kind::LANDDINO);
  //! Destruktor.
  virtual ~LandDino();
  virtual int eatMe() override;

private:
  //! Funkcja wyszukująca najbliższego partnera, zodpowiednim gatunkiem
  //! i płcią, a następnie zwracająca wskaźnik na ten obiekt dinozaura.
  AliveEntity *findMate() override;\
  //! Funkcja próbująca rozmnażać dinozaury. Próba może być nieudana gdy
  //! partner jest za daleko lub jest złego typu. Wyzerowuje płodność dinozaura.
  void mating() override;
  //! Funkcja łącząca dinozaury w parę.
  void pair(AliveEntity *new_mate) override;
  //! Funkcja rozłączająca parę.
  void unpair() override;
};
}
#endif // LANDDINO_H
