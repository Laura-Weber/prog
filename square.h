#ifndef SQUARE_H
#define SQUARE_H

#include "defs.h"

typedef struct square_ptr{
  int x;
  int y;
  struct square_ptr * next;
}*list_square;

#endif /* SQUARE_H */
