#ifndef GRASS_H
#define GRASS_H

#include "plant.h"

namespace WDWE::logic::entities
{
class Grass : public Plant
{
public:
  Grass(WorldMap *world_map, QPointF position, Kind kind = Kind::GRASS);
  virtual ~Grass();
  void tick() override;
  int eatMe() override;

protected:
  void spread() override;
  void grow() override;

  int getLenght() const;
  int getMaxLenght() const;
  int getNutrientPerPiece() const;
  void incLenght(int value = 1);

private:
  int lenght_;
  int max_lenght_;
  int nutrient_per_piece_;

};
}
#endif // GRASS_H
