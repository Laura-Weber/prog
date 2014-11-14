#include "defs.h"

list_piece * creat_list_piece()
{
  list_piece * new_l = (list_piece*)malloc(sizeof (list_piece));
  new_l->first_piece = NULL;
  return new_l;
}

piece * creat_piece()
{
  int i;
  piece * new_p = (piece*)malloc(sizeof (piece));

  new_p->bitmap = NULL;
  for(i = 0; i < 8; i++){
    new_p->rotate_tab[i] = creat_list_square();
  }

  new_p->rotation_actual = 0;
  new_p->next = NULL;
  new_p->sur_plateau = 0;
  return new_p;
}

void add_piece(list_piece *LP, piece *P)
{

  if(LP->first_piece != NULL){

    P->next = LP->first_piece;
    LP->first_piece = P;
  }else{

    LP->first_piece = P;
    P->next = NULL;
  }

}

list_square * rotation_90(list_square * LS){

  list_square * new_l = creat_list_square();
  square * S = LS->first_square;
  int min_y = 0,min_x = 0;

  while(S){

    if(min_y > -(S->x)){
      min_y = -(S->x);
    }
    if(min_x > S->y){
      min_x = S->y;
    }

    add_square(new_l,S->y,-(S->x));
    S = S->next;

  }
  if(min_y < 0 && min_x < 0){
    S = new_l->first_square;

    while(S){
      S->y -= min_y;
      S->x -= min_x;
      S = S->next;
    }

  }else if(min_y < 0){
    S = new_l->first_square;

    while(S){
      S->y -= min_y;
      S = S->next;

    }
  }else if(min_x < 0){
    S = new_l->first_square;

    while(S){

      S->x -= min_x;
      S = S->next;
    }
  }

  return new_l;
}

list_square * symetrique(list_square * LS){

  list_square * new_l = creat_list_square();
  square * S = LS->first_square;
  int min_y = 0;

  while(S){

    if(min_y > -(S->y)){
      min_y = -(S->y);
    }

    add_square(new_l,S->x,-(S->y));
    S = S->next;

  }

  if(min_y < 0){
    S = new_l->first_square;

    while(S){
      S->y -= min_y;
      S = S->next;
    }
  }

  return new_l;
}

void make_rotation(piece * p){

  p->rotate_tab[1] = rotation_90(p->rotate_tab[0]);
  p->rotate_tab[2] = rotation_90(p->rotate_tab[1]);
  p->rotate_tab[3] = rotation_90(p->rotate_tab[2]);


  p->rotate_tab[4] = symetrique(p->rotate_tab[0]);
  p->rotate_tab[5] = symetrique(p->rotate_tab[1]);
  p->rotate_tab[6] = symetrique(p->rotate_tab[2]);
  p->rotate_tab[7] = symetrique(p->rotate_tab[3]);

}

void move_piece(piece * p ,int x,int y)
{
  p->x = x;
  p->y = y;
}



