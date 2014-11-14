#ifndef LIST_PIECE_H
#define LIST_PIECE_H

#include "defs.h"
typedef struct piece{

    list_square * rotate_tab[8];

    SDL_Surface * bitmap;

    int sur_plateau;
    int rotation_actual;
    /*position de l'objet dans la fenetre */
    unsigned int x;
    unsigned int y;

    struct piece * next;

}piece;

typedef struct list_piece{

    piece * first_piece;

}list_piece;


list_piece * creat_list_piece();
piece * creat_piece();
void add_piece(list_piece *LP, piece *P);

void move_piece(piece * p ,int x,int y);

//piece * select(list_piece * LP, int x, int y);

list_square * rotation_90(list_square * LS);

list_square * symetrique(list_square * LS);


void make_rotation(piece * p);

#endif // LIST_PIECE_H
