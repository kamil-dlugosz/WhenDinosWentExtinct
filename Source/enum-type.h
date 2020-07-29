#ifndef ENUMTYPE_H
#define ENUMTYPE_H

namespace WDWE::logic::disasters
{
//! Typ enumeratywny definiujący katastrofy.
enum Type {
  INVALID = 0,

  INFERNO,
  METEOR,
  GAMMARAY,
  DROUGHT,
  ANNIHILATION,

  TOTAL
};
}
#endif // ENUMTYPE_H
