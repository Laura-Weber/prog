#include "defs.h"

list_square * creat_list_square()
{
  list_square * new_l = (list_square*)malloc(sizeof (list_square));
  new_l->first_square = NULL;
  return new_l;
}

void add_square (list_square * LS, int x , int y)
{
  square * new_s = (square *)malloc(sizeof (square));
  new_s->x = x;
  new_s->y = y;
  if(LS->first_square){
    new_s->next = LS->first_square;
    LS->first_square = new_s;
  }else{
    LS->first_square = new_s;
    new_s->next = NULL;
  }
}
