#ifndef ENTITY_H
#define ENTITY_H

#include <QVector>
#include <QPointF>
#include "enum-kind.h"
#include "enum-biome.h"

namespace WDWE::logic
{
class WorldMap;

namespace entities
{
//! Klasa implementująca ogólne cechy istot.
class AliveEntity
{  
public:
  //! Konstruktor.
  AliveEntity(WorldMap *world_map, Kind getKind, QPointF position = QPointF(0, 0));
  //! Destruktor.
  virtual ~AliveEntity();
  //! Funkcja aktualizująca paramety istoty z każdym krokiem symulacji.
  //! Regeneruje życie, zarządza głodem, płodnością, itp.
  virtual void tick();
  //! Funkcja reagująca na bycie zjadanym. Zwraca wartość odżywczą.
  virtual int eatMe() = 0;
  Kind getKind() const;
  QPointF getPosition() const;
  int getAge() const;
  int getFertility() const;
  //! Zwraca true gdy istota jest żywa (dodatnie życie,
  //! wiek mniejszy od maksimum itp.)
  bool isAlive();
  //! Zwraca true gdy istota jest płoda.
  bool isFertile();
  //! Zwiększanie życia aż do osiągnięcia maksymalnej wartości.
  void incHealth(int value = 1);

protected:
  WorldMap *getWorldMap() const;
  void setPosition(QPointF position);
  //! Oznacza istotę jako martwą.
  void killMe();
  //! Ustawia wektor biomów dozwolonych dla istot. Gdy są poza nią otrzymują obrażenia.
  void setAllowedBiomes(QVector<Biome> new_biomes);
  QVector<Biome> getAllowedBiomes();
  //! Zwraca true gdy jest w jednym z dozwolonych biomów.
  bool isInGoodBiome(QPointF point);
  //! Zwraca true gdy istota jest w płodnym wieku.
  virtual bool isAdult() const;
  //! Zwiększanie wieku aż do osiągnięcia maksymalnej wartości.
  bool incAge(int value = 1);
  //! Zwiększanie płodności aż do osiągnięcia maksymalnej wartości.
  bool incFertility(int value = 1);
  //! Zwiększanie najedzenia aż do osiągnięcia maksymalnej wartości.
  void incSaturation(int value = 1);
  //! Ustawia płodność na 0;
  void resetFertility();
  void setSaturation(int value = 0);
  void setMaxFertility(int value);
  int getMaxHealth() const;
  int getMaxAge() const;
  int getSaturation() const;
  int getMaxSaturation() const;
  int getHealth() const;

private:
  WorldMap *const world_map_;
  const Kind kind_;
  int max_health_;
  float max_age_;
  int max_fertility_;
  int max_saturation_;
  int health_;
  float age_;
  int fertility_;
  int saturation_;
  QPointF position_;
  QVector<Biome> allowed_biomes_;
  bool is_alive_;
};
}}
#endif // ENTITY_H
