#ifndef PLANT_H
#define PLANT_H

#include "entity.h"

namespace WDWE::logic::entities
{
//! Abstrakcyjna klasa definiująca ogólne cechy roślin.
class Plant : public AliveEntity
{
public:
  //! Konstruktor.
  Plant(WorldMap *world_map, QPointF position, Kind kind);
  //! Destruktor.
  virtual ~Plant();
  //! Funkcja aktualizująca paramety roślin z każdym krokiem symulacji.
  //! Regeneruje życie, zarządza głodem, płodnością, rośnięciem.
  virtual void tick() override;
  //! Funkcja reagująca na bycie zjadanym. Zwraca wartość odżywczą.
  virtual int eatMe() override = 0;

protected:
  //! Zwraca true gdy roślina jest w wegetatywnym wieku.
  bool isAdult() const override;
  //! Zwraca true gdy roślina jest zdolna do rozrostu.
  bool isSaturated() const;
  int getSpreadRate() const;
  int getGrowthRate() const;
  int getSeedNumber() const;

  //! Funkcja rozpszestrzeniająca rośliny na planszy.
  virtual void spread();
  //! Funkcja realizująca rośnięcie roślin.
  virtual void grow() = 0;

private:
  int spread_rate_;
  int growth_rate_;
  int seed_number_;
};
}
#endif // PLANT_H
