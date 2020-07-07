#ifndef DINO_H
#define DINO_H

#include "entity.h"

namespace WDWE::logic::entities
{
class Dino : public Entity
{
public:
  enum class Sex {
    MALE,
    FEMALE
  };
  Dino(WorldMap *world_map, Kind getKind);
  virtual ~Dino();
  virtual void tick() override;
  int eatMe() override;
  Entity *getTarget() const;
  void setTarget(Entity *new_target);
  virtual bool isReadyToMate();
  bool isFertile();
  void resetFertility();

protected:
  bool isHungry() const;
  bool isFed() const;
  bool isAdult() const;
  bool isYummy(Kind food) const;

  int getMinViewDist() const;
  int getMaxViewDist() const;
  Sex sex() const;

  virtual Entity *findFood();
  virtual Entity *findMate() = 0;
  virtual void eat();
  virtual void mating() = 0;
  virtual void pair(Entity *target) = 0;
  virtual void unpair();
  virtual bool move();

private:
  const int max_saturation_;
  const int hgh_saturation_;
  const int low_saturation_;
  const int min_view_dist_;
  const int max_view_dist_;
  const int max_fertility_;
  //const int max_speed_;
  const float max_age_;
  const Sex sex_;
  const Kind diet_;

  int satutation_;
  int fertility_;
  int speed_;
  float age_;
  Entity *target_;
};
}
#endif // DINO_H
