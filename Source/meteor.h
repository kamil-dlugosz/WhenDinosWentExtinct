#ifndef METEOR_H
#define METEOR_H

#include "inferno.h"

namespace WDWE::logic::disasters
{
//! Klasa implementująca Upadek meteorytu - oprócz funkcjonalności Pożaru dodaje
//! krater wokół środka zamieniając podłoże w kamień.
class Meteor : public Inferno
{
public:
  //! Konstruktor.
  explicit Meteor(WorldMap *world_map, int duration, int max_size, float spread_pace);
  //! Destruktor.
  virtual ~Meteor();
  //! Funckja aktualizująca parametry katastrofy za każdym krokiem symulacji.
  void tick() override;

private:
  int explosion_radius_;

  //! Funkcja realizująca upadek meteorytu - zamienia obszar w kamień.
  void meteorFall();
};
}
#endif // METEOR_H
