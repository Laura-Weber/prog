#ifndef LIST_SQUARE_H
#define LIST_SQUARE_H

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

struct list_square_ptr
{
    struct list_square_ptr * next;
    struct list_square_ptr * prev;
    SDL_Surface * square;
    SDL_Rect pos;
};

typedef struct dlist_square_ptr
{
    size_t lenght;
    struct list_square_ptr *tail;
    struct list_square_ptr *head;
}*Dlist_square;

/***************************/
/*  Function prototypes    */
/***************************/

Dlist_square new_list_square();

      ////////////////////////
      //    constructeur    //
      ////////////////////////

Dlist_square add_square(Dlist_square LS, char * bmp, SDL_Rect n_pos);

      ////////////////////////////
      //    reading function    //
      ////////////////////////////

size_t nb_square(Dlist_square LS);

      ////////////////////////////
      //    writing function    //
      ////////////////////////////

void coord_square(struct list_square_ptr *S, SDL_Rect n_pos);

      /////////////////////////
      //    free function    //
      /////////////////////////

void free_list_square(Dlist_square * LS);

#endif // LIST_SQUARE_H
