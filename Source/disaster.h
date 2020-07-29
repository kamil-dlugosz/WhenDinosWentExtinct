#ifndef DISASTER_H
#define DISASTER_H

#include "worldmap.h"
#include "enum-type.h"

namespace WDWE::logic::disasters
{
//! Abstrakcyjna klasa implementująca ogólne cechy Katastrof.
class Disaster
{  
public:
  //! Konstruktor.
  explicit Disaster(WorldMap *world_map, int duration, Type type);
  //! Destruktor.
  virtual ~Disaster();
  //! Funckja aktualizująca parametry katastrofy za każdym krokiem symulacji.
  virtual void tick();
  //! Funkcja zwracająca typ katastrofy.
  Type getType() const;
  //! Zwraca true, gdy katastrofa dobiegnie końca.
  bool hasEnded() const;

protected:
  //! Zwraca wskaźnik na planszę.
  WorldMap *getWorldMap() const;
  //! Zwraca maksymalną ilość kroków symulacji, która będzie trwać katastrofa.
  int getDurationTotal() const;
  //! Zwraca ilość kroków symulacji, którą jeszcze będzie trwać katastrofa.
  int getDurationLeft() const;
  //! Kończy katastofę.
  void endDisaster();

private:
  WorldMap *const world_map_;
  const Type type_;
  const int duration_total_;
  int duration_left_;
};
}
#endif // DISASTER_H
