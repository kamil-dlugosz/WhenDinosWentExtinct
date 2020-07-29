#ifndef INFERNO_H
#define INFERNO_H

#include <QPoint>
#include "disaster.h"

namespace WDWE::logic::disasters
{
//! Klasa implementująca Pożar - stopniowo obszar wokół centrum jest zamieniany
//! w piasek (wyjątkiem jest woda) oraz zabijane są istoty.
class Inferno : public Disaster
{
public:
  //! Konstruktor.
  explicit Inferno(WorldMap *world_map, int duration, int max_size, float spread_pace,
          Type type = Type::INFERNO);
  //! Destruktor.
  virtual ~Inferno();
  //! Funckja aktualizująca parametry katastrofy za każdym krokiem symulacji.
  void tick() override;

protected:
  QPointF getCenter();
  void setCenter(QPointF new_center);
  int getSpreadPace() const;
  int getSize() const;
  int getMaxSize() const;
  //! Zamiana gleby w piasek w obszarze pożaru.
  void destroySoil();
  //! Zabijanie istot w obszarze pożaru.
  void killEntities();
  //! Zwiększanie obszaru aż do osiągnięcia maksymalnej wartości.
  void incSize(float value);

private:
  QPointF center_;
  float max_size_;
  float size_;
  float spread_pace_;
};
}
#endif // INFERNO_H
