#ifndef WATERDINO_H
#define WATERDINO_H

#include "dino.h"

namespace WDWE::logic::entities
{
//! Klasa definiująca dinozaury pływające.
class WaterDino : public Dino
{
public:
  //! Konstruktor.
  WaterDino(WorldMap *world_map, QPointF position, Kind kind = Kind::WATERDINO);
  //! Destruktor.
  virtual ~WaterDino();
  //! Funkcja reagująca na bycie zjadanym. 50% szans, że zostanie zjedzony.
  //! Zwraca wartość odżywczą oraz zabija dinozaura gdy pomyślne. Gdy nie -
  //! zwraca 0;
  int eatMe() override;

private:
  //! Funkcja wyszukująca najbliższego partnera, zodpowiednim gatunkiem
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
#endif // WATERDINO_H
