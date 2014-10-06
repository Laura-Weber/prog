#ifndef SQUARE_H
#define SQUARE_H

#include "defs.h"
#include "list_piece.h"

typedef struct square_ptr{
  int x;
  int y;
  struct square_ptr * next;
}*list_square;

list_square empty_square();
list_square new_square(list_square S, int x, int y);
void coord_square(list_square S, int x, int y);

#endif /* SQUARE_H */
