#include "square.h"

square empty_square()
{
  return NULL;
}

square new_square(square S, int x, int y)
{
  square new_s = empty_square();
  new_s = (square)malloc(sizeof(struct square_ptr));
  new_s->x = x;
  new_s->y = y;
  new_s->next = S
  return new_s;
}

void coord_square(square S, int x, int y)
{
  S->x = x;
  S->y = y;
}
