#ifndef DINO_H
#define DINO_H

#include "entity.h"

namespace WDWE::logic::entities
{
class Dino : public AliveEntity
{
public:
  enum class Sex {
    MALE,
    FEMALE
  };
  Dino(WorldMap *world_map, QPointF position, Kind getKind);
  virtual ~Dino();
  virtual void tick() override;
  int eatMe() override;
  Dino *getMate() const;
  void setMate(Dino *new_mate);
  virtual bool isReadyToMate();

protected:
  void setDiet(QVector<Kind> new_diet);
  QVector<Kind> getDiet();

  bool isStarving() const;
  bool isHungry() const;
  bool isFed() const;
  bool isYummy(Kind food) const;

  int getHghSaturation() const;
  int getLowSaturation() const;
  int getMinViewDist() const;
  int getMaxViewDist() const;
  Sex getSex() const;

  virtual AliveEntity *findFood();
  virtual AliveEntity *findMate() = 0;
  virtual void eat(AliveEntity *prey);
  virtual void mating() = 0;
  virtual void pair(AliveEntity *target) = 0;
  virtual void unpair();
  virtual bool move(QPointF destination);

private:
  int hgh_saturation_;
  int low_saturation_;
  int min_view_dist_;
  int max_view_dist_;
  const Sex sex_;
  QVector<Kind> diet_;

  int speed_;
  Dino *mate_;
};
}
#endif // DINO_H
