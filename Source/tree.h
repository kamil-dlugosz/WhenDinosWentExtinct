#ifndef TREE_H
#define TREE_H

#include "plant.h"

namespace WDWE::logic::entities
{
//! Klasa implementująca drzewo.
class Tree : public Plant
{
public:
  //! Konstruktor.
  Tree(WorldMap *world_map, QPointF position, Kind getKind = Kind::TREE);
  //! Destruktor.
  virtual ~Tree();
  //! Funkcja aktualizująca paramety roślin z każdym krokiem symulacji.
  //! Regeneruje życie, zarządza głodem, płodnością, rośnięciem.
  void tick() override;
  int eatMe() override;

  int getMaxLeaves() const;
  int getLeavesNumber() const;
  int getNutrientsPerLeaf() const;
  int getMaxFruitsNumber() const;
  int getFruitsNumber() const;
  int getNutrientsPerFruit() const;

protected:
  //! Funkcja rozpszestrzeniająca rośliny na planszy.
  void spread() override;
  //! Funkcja realizująca rośnięcie roślin.
  void grow() override;
  //! Zwiększanie liczby liści aż do osiągnięcia maksymalnej wartości.
  bool incLeaves(int value = 1);
  //! Zwiększanie liczby owoców aż do osiągnięcia maksymalnej wartości.
  bool incFruits(int value = 1);

private:
  int max_leaves_number_;
  int leaves_number_;
  int nutrients_per_leaf_;
  int max_fruits_number_;
  int fruits_number_;
  int nutrients_per_fruit_;
};
}
#endif // TREE_H
