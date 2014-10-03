#ifndef PLATEAU_H
#define PLATEAU_H
#include "defs.h"

typedef struct Point{
  int x;
  int y;
} point;

typedef struct Plateau{
  point bg;
  point hd;
} plateau;

typedef struct {             // Structure de couleur
  octet R, V, B ;            // composée des 3 bases
} couleur ;   

#endif /*plateau.h*/
