#ifndef ANIHILATION_H
#define ANIHILATION_H

#include "disaster.h"
#include "entity.h"
#include "enum-kind.h"

namespace WDWE::logic::disasters
{
//! Klasa implementująca Anihilację - pełne usunięcie danego gatunku.
class Annihilation : public Disaster
{
public:
  //! Konstruktor.
  explicit Annihilation(WorldMap *world_map, entities::Kind target);
  //! Destruktor.
  virtual ~Annihilation();
  //! Funckja aktualizująca parametry katastrofy za każdym krokiem symulacji.
  void tick() override;

private:
  entities::Kind target_;
  //! Funkcja zabijająca cały gatunek.
  void killWholeKind(entities::Kind target);
};
}
#endif // ANIHILATION_H
