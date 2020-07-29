#ifndef DINO_H
#define DINO_H

#include "entity.h"

namespace WDWE::logic::entities
{
//! Abstrakcyjna klasa definiująca ogólny cechy dinozaura.
class Dino : public AliveEntity
{
public:
  //! Typ enumeratywny definiujący płcie.
  enum class Sex {
    INVALID = 0,

    MALE,
    FEMALE,

    TOTAL
  };
  //! Konstruktor.
  Dino(WorldMap *world_map, QPointF position, Kind getKind);
  //! Destruktor.
  virtual ~Dino();
  //! Funkcja aktualizująca paramety dinozaura z każdym krokiem symulacji.
  //! Regeneruje życie, zarządza głodem, płodnością, szukaniem jedzenia,
  //! partnerów itp.
  virtual void tick() override;
  Dino *getMate() const;
  void setMate(Dino *new_mate);
  //! Zwraca true, gdy dinozaur jest gotowy do rozmnażania (najedzony, dorosły,
  //! ale nie stary, płodny itp.)
  virtual bool isReadyToMate();

protected:
  void setDiet(QVector<Kind> new_diet);
  QVector<Kind> getDiet();

  //! Zwraca true gdy poziom najedzenia ma wartość 0.
  bool isStarving() const;
  //! Zwraca true gry poziom najedzenia jest niski.
  bool isHungry() const;
  //! Zwraca true gdy poziom najedzenia jest wysoki.
  bool isFed() const;
  //! Zwraca true gdy food należy do diety dinozaura.
  bool isYummy(Kind food) const;

  int getHghSaturation() const;
  int getLowSaturation() const;
  int getMinViewDist() const;
  int getMaxViewDist() const;
  Sex getSex() const;

  //! Funkcja wyszukująca najbliższe jedzenie zgodne z dietą, a następnie
  //! zwracająca wskaźnik na ten obiekt jedzenia.
  virtual AliveEntity *findFood();
  //! Funkcja wyszukująca najbliższego partnera, zodpowiednim gatunkiem
  //! i płcią, a następnie zwracająca wskaźnik na ten obiekt dinozaura.
  virtual AliveEntity *findMate() = 0;
  //! Funkcja próbująca zjeść obiekt znajdujący się pod wskaźnikiem.
  //! Próba może się nie udać np. gdy cel będzie za daleko lub ucieknie.
  virtual void eat(AliveEntity *prey);
  //! Funkcja próbująca rozmnażać dinozaury. Próba może być nieudana gdy
  //! partner jest za daleko lub jest złego typu. Wyzerowuje płodność dinozaura.
  virtual void mating() = 0;
  //! Funkcja łącząca dinozaury w parę.
  virtual void pair(AliveEntity *target) = 0;
  //! Funkcja rozłączająca parę.
  virtual void unpair();
  //! Funkcja zmieniająca położenie dinozaura w stronę celu.
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
