/****************************/
/* WEBER Laura, SCHMITT Lea */
/* L2 info                  */
/* list_square.c            */
/****************************/

/**************************************/
/* Useful library inclusion           */
/**************************************/

#include "defs.h"

/*******************************************************************/
/*             FUNCTION DEFINITION                                 */
/*******************************************************************/

Dlist_square new_list_square()
{
    Dlist_square new_l = malloc(sizeof *new_l);
    if (new_l != NULL){
        new_l->lenght = 0;
        new_l->head = NULL;
        new_l->tail = NULL;
    }
    return new_l;
}

      ////////////////////////
      //    constructeur    //
      ////////////////////////

Dlist_square add_square(Dlist_square LS, char * bmp, SDL_Rect n_pos)
{
    if(LS != NULL){
        struct list_square_ptr *new_s = NULL;
        new_s = malloc(sizeof *new_s);
        if(new_s != NULL){
            new_s->square = SDL_LoadBMP(bmp);
            new_s->pos = n_pos;
            new_s->next = NULL;
            if(LS->tail == NULL){
                new_s->prev = NULL;
                LS->tail = new_s;
                LS->head = new_s;
            }else{
                LS->tail->next = new_s;
                new_s->prev = LS->tail;
                LS->tail = new_s;
            }
            LS->lenght++;
        }
    }
    return LS;
}

      ////////////////////////////
      //    reading function    //
      ////////////////////////////

size_t nb_square(Dlist_square LS)
{
    size_t nb = 0;
    if(LS != NULL){
        nb = LS->lenght;
    }
    return nb;
}

      ////////////////////////////
      //    writing function    //
      ////////////////////////////

void coord_square(struct list_square_ptr * S, SDL_Rect n_pos)
{
    S->pos = n_pos;
}

      /////////////////////////
      //    free function    //
      /////////////////////////

void free_list_square(Dlist_square * LS)
{
    if(*LS != NULL){
        struct list_square_ptr * temp = (*LS)->head;
        while(temp != NULL){
            struct list_square_ptr * del = temp;
            temp = temp->next;
            free(del);
        }
        free(*LS), *LS = NULL;
    }
}
