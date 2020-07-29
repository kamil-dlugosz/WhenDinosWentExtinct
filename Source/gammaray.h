#ifndef GAMMARAY_H
#define GAMMARAY_H

#include "disaster.h"

namespace WDWE::logic::disasters
{
//! Klasa implementująca Promieniowanie Gamma -
//! co jakiś czas zmniejszane jest życie dinozaurów.
class GammaRay : public Disaster
{
public:
  //! Konstruktor.
  explicit GammaRay(WorldMap *world_map, int duration, int hp_decrease);
  //! Destruktor.
  virtual ~GammaRay();
  //! Funckja aktualizująca parametry katastrofy za każdym krokiem symulacji.
  void tick() override;

private:
  int hp_decrease_;

  //! Funkcja zadająca obrażenia dinozaurom.
  void damageDinos();
};
}
#endif // GAMMARAY_H
