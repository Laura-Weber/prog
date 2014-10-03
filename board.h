#ifndef PLATEAU_H
#define PLATEAU_H
#include "defs.h"

typedef unsigned char octet;

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

void ColoriePixel (int x, int y, TCouleur C);
void dessine_segment(point p1, point p2)
void print_board()

#endif /*plateau.h*/
