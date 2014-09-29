#ifndef SQUARE_H
#define SQUARE_H

#include "defs.h"

typedef struct square_ptr{
  int x;
  int y;
  struct part * next;
}*square;

#endif /* SQUARE_H */
