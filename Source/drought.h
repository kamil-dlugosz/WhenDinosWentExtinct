#ifndef DROUGHT_H
#define DROUGHT_H

#include "disaster.h"

namespace WDWE::logic::disasters
{
//! Klasa implementująca suszę - powoli biomy zamieniają się w piasek.
class Drought : public Disaster
{
public:
  //! Konstruktor.
  explicit Drought(WorldMap *world_map, int duration, float drying_rate);
  //! Destruktor.
  virtual ~Drought();
  //! Funckja aktualizująca parametry katastrofy za każdym krokiem symulacji.
  void tick() override;

protected:
  //! Zwraca szybkość wysuszania terenu.
  int getDryingRate() const;

private:
  float drying_rate_;

  //! Wysuszanie terenu.
  void dryingBiomes();
  //! Zwraca true, gdy jedno z sąsiednich pól do (x,y) jest typu biome.
  bool checkNeighbours(Biome biome, int x, int y);
};
}
#endif // DROUGHT_H
