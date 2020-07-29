#ifndef GRASS_H
#define GRASS_H

#include "plant.h"

namespace WDWE::logic::entities
{
//! Klasa implementująca Trawę.
class Grass : public Plant
{
public:
  //! Konstruktor.
  Grass(WorldMap *world_map, QPointF position, Kind kind = Kind::GRASS);
  //! Destruktor.
  virtual ~Grass();
  //! Funkcja aktualizująca paramety roślin z każdym krokiem symulacji.
  //! Regeneruje życie, zarządza głodem, płodnością, rośnięciem.
  virtual void tick() override;
  //! Funkcja reagująca na bycie zjadanym. Zwraca wartość odżywczą.
  int eatMe() override;

protected:
  //! Funkcja rozpszestrzeniająca rośliny na planszy.
  virtual void spread() override;
  //! Funkcja realizująca rośnięcie roślin.
  virtual void grow() override;

  int getLenght() const;
  int getMaxLenght() const;
  int getNutrientPerPiece() const;
  //! Zwiększanie długości rośliny aż do osiągnięcia maksymalnej wartości.
  void incLenght(int value = 1);

private:
  int lenght_;
  int max_lenght_;
  int nutrient_per_piece_;
};
}
#endif // GRASS_H
