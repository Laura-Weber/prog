#ifndef LIST_PIECE_H
#define LIST_PIECE_H

#include "defs.h"

typedef struct piece_ptr{
  list_square square;
  struct piece_ptr * next;
} *list_piece;

list_piece empty_list (void);
list_piece add_piece(list_piece L, list_square S);
int nb_piece(list_piece P);
void up_piece(list_piece P);
void down_piece(list_piece P);
void up_piece(list_piece P);
void right_piece(list_piece P);
void left_piece(list_piece P);
void creat_list_piece(list_piece P);
list_piece rotate_r(list_piece P);
list_piece rotate_l(list_piece P);
    	
#endif /* LIST_PIECE_H */
 
