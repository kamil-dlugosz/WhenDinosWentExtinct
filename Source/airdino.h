#ifndef AIRDINO_H
#define AIRDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
//! Klasa definiująca dinozaury latające.
class AirDino : public Dino
{
public:
  //! Konstruktor.
  AirDino(WorldMap *world_map, QPointF position, Kind kind = Kind::AIRDINO);
  //! Destruktor.
  virtual ~AirDino();
  //! Funkcja reagująca na bycie zjadanym. 90% szans, że zostanie zjedzony.
  //! Zwraca wartość odżywczą oraz zabija dinozaura gdy pomyślne. Gdy nie -
  //! zwraca 0.
  int eatMe() override;

private:
  //! Funkcja wyszukująca najbliższeg4o partnera, zodpowiednim gatunkiem
  //! i płcią, a następnie zwracająca wskaźnik na ten obiekt dinozaura.
  AliveEntity *findMate() override;
  //! Funkcja próbująca rozmnażać dinozaury. Próba może być nieudana gdy
  //! partner jest za daleko lub jest złego typu. Wyzerowuje płodność dinozaura.
  void mating() override;
  //! Funkcja łącząca dinozaury w parę.
  void pair(AliveEntity *new_mate) override;
  //! Funkcja rozłączająca parę.
  void unpair() override;
};
}
#endif // AIRDINO_H
