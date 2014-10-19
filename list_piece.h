#ifndef LIST_PIECE_H
#define LIST_PIECE_H

/****************************/
/* WEBER Laura, SCHMITT Lea */
/* L2 info                  */
/* list_square.h            */
/****************************/

/**************************************/
/* Useful library inclusion           */
/**************************************/

#include "defs.h"

/*******************/
/*    Structure    */
/*******************/

struct list_piece_ptr
{
    struct list_piece_ptr * next;
    struct list_piece_ptr * prev;
    struct dlist_square_ptr * S;
};

typedef struct dlist_piece_ptr
{
    size_t lenght;
    struct list_piece_ptr *tail;
    struct list_piece_ptr *head;
}*Dlist_piece;

/***************************/
/*  Function prototypes    */
/***************************/

Dlist_piece new_list_piece();

      ////////////////////////
      //    constructeur    //
      ////////////////////////

Dlist_piece add_piece(Dlist_piece LP, Dlist_square square);
Dlist_piece creat_list_piece();

      ////////////////////////////
      //    reading function    //
      ////////////////////////////

size_t nb_piece(Dlist_piece LP);

      /////////////////////////
      //    free function    //
      /////////////////////////

void free_list_piece(Dlist_piece * LP);

      //////////////////////////
      //    move function     //
      //////////////////////////

void up_piece(struct list_piece_ptr *P);
void down_piece(struct list_piece_ptr *P);
void right_piece(struct list_piece_ptr *P);
void left_piece(struct list_piece_ptr *P);
void rotate_r(struct list_piece_ptr *P);
void rotate_l(struct list_piece_ptr *P);

      //////////////////////////
      //    blitt function    //
      //////////////////////////

void blitt_piece(Dlist_piece LP, SDL_Surface *screen);

#endif // LIST_PIECE_H
