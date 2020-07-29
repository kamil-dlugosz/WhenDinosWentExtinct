#ifndef ENUMKIND_H
#define ENUMKIND_H

namespace WDWE::logic::entities
{
//! Typ enumeratywny definiujący gatunki istot.
enum Kind {
  INVALID = 0,

  AIRDINO,
  LANDDINO,
  WATERDINO,
  ALGA,
  BUSH,
  GRASS,
  TREE,

  TOTAL
};
}

#endif // ENUMKIND_H
