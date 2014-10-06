#include "defs.h"

list_square empty_square()
{
  return NULL;
}

list_square new_square(list_square S, int x, int y)
{
  list_square new_s = empty_square();
  new_s = (list_square)malloc(sizeof(struct square_ptr));
  new_s->x = x;
  new_s->y = y;
  new_s->next = S
  return new_s;
}

void coord_square(list_square S, int x, int y)
{
  S->x = x;
  S->y = y;
}
