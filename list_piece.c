/****************************/
/* WEBER Laura, SCHMITT Lea */
/* L2 info                  */
/* list_piece.c             */
/****************************/

/**************************************/
/* Useful library inclusion           */
/**************************************/

#include "defs.h"

/*******************************************************************/
/*             FUNCTION DEFINITION                                 */
/*******************************************************************/

Dlist_piece new_list_piece()
{
    Dlist_piece new_l = malloc(sizeof *new_l);
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

Dlist_piece add_piece(Dlist_piece LP, Dlist_square square)
{
    if(LP != NULL){
        struct list_piece_ptr *new_l = malloc(sizeof *new_l);
        if (new_l != NULL){
            new_l->S = square;
            new_l->next = NULL;
            if(LP->tail == NULL){
                new_l->prev = NULL;
                LP->head = new_l;
                LP->tail = new_l;
            }else{
                LP->tail->next = new_l;
                new_l->prev = LP->tail;
                LP->tail = new_l;
            }
            LP->lenght++;
        }
    }
    return LP;
}

Dlist_piece creat_list_piece()
{
    Dlist_piece LP = NULL;
    LP = malloc(sizeof *LP);
    FILE * fichier;
    int caractereActuel;
    int nouv = 0;
    char * tab[100][6];
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    pos.h = BLOC_SIZE;
    pos.w = BLOC_SIZE;
    tab[100][0] = "c_bleuc.bmp";
    tab[100][1] = "c_jauc.bmp";
    tab[100][2] = "c_rosec.bmp";
    tab[100][3] = "c_rosef.bmp";
    tab[100][4] = "c_vertc.bmp";
    tab[100][5] = "c_viof.bmp";
    int i = 0;

    fichier = fopen("pentomino.txt", "r+w");
    rewind(fichier);

    if(fichier != NULL){
        while(caractereActuel != EOF){
            caractereActuel = fgetc(fichier);
            if (caractereActuel == '#'){
                LP->head->S = add_square(LP->head->S,tab[100][i], pos);
                pos.x += 1;
                nouv = 0;
            }
            if (caractereActuel == '\n' && nouv == 0){
                pos.y += 1;
                pos.x = 0;
                nouv = 1;
            }
            if (caractereActuel == '\n' && nouv == 1){
                LP = add_piece(LP,LP->head->S);
                pos.x = 0;
                pos.y = 0;
                nouv = 0;
                if(i == 6){
                    i = 0;
                }else{
                    i++;
                }
            }
        }
    fclose(fichier);
    }else{
        printf("erreur fichier vide\n");
	}
    return LP;
}

      ///////////////////
      //    lecture    //
      ///////////////////

size_t nb_piece(Dlist_piece LP)
{
    size_t nb = 0;
    if(LP != NULL){
        nb = LP->lenght;
    }
    return nb;
}

      /////////////////////////
      //    free function    //
      /////////////////////////

void free_list_piece(Dlist_piece * LP)
{
    if(*LP != NULL){
        struct list_piece_ptr * temp = (*LP)->head;
        while(temp != NULL){
            struct list_piece_ptr * del = temp;
            temp = temp->next;
            free(del);
        }
        free(*LP), *LP = NULL;
    }
}

      //////////////////////////
      //    move function     //
      //////////////////////////

void up_piece(struct list_piece_ptr *P)
{
  while (P->S != NULL){
    P->S->head->pos.y -= 1;
    P->S->head = P->S->head->next;
  }
}

void down_piece(struct list_piece_ptr *P)
{
  while (P->S->head != NULL){
    P->S->head->pos.y += 1;
    P->S->head = P->S->head->next;
  }
}

void right_piece(struct list_piece_ptr *P)
{
  while (P->S->head != NULL){
    P->S->head->pos.x += 1;
    P->S->head = P->S->head->next;
  }
}

void left_piece(struct list_piece_ptr *P)
{
  while (P->S->head != NULL){
    P->S->head->pos.x -= 1;
    P->S->head = P->S->head->next;
  }
}

void rotate_r(struct list_piece_ptr *P)
{
  while(P->S->head != NULL){
    if(P->S->head->pos.x == 0){
  	P->S->head->pos.x = P->S->head->pos.y;
  	P->S->head->pos.y = 3;
    }
    if(P->S->head->pos.x == 1){
  	P->S->head->pos.x = P->S->head->pos.y;
  	P->S->head->pos.y = 2;
    }
    if(P->S->head->pos.x == 2){
    	P->S->head->pos.x = P->S->head->pos.y;
    	P->S->head->pos.y = 1;
    }
    if(P->S->head->pos.x == 3){
    	P->S->head->pos.x = P->S->head->pos.y;
    	P->S->head->pos.y = 0;
    }
  P->S->head = P->S->head->next;
  }
}

void rotate_l(struct list_piece_ptr *P)
{
  while(P->S->head != NULL){
    if(P->S->head->pos.y == 0){
      P->S->head->pos.y = P->S->head->pos.x;
      P->S->head->pos.x = 3;
    }
    if(P->S->head->pos.y == 1){
      P->S->head->pos.y = P->S->head->pos.x;
      P->S->head->pos.x = 2;
    }
    if(P->S->head->pos.y == 2){
      P->S->head->pos.y = P->S->head->pos.x;
      P->S->head->pos.x = 1;
    }
    if(P->S->head->pos.y == 3){
      P->S->head->pos.y = P->S->head->pos.x;
      P->S->head->pos.x = 0;
    }
    P->S->head = P->S->head->next;
  }
}

      //////////////////////////
      //    blitt function    //
      //////////////////////////

void blitt_piece(Dlist_piece LP, SDL_Surface *screen)
{
    if(LP != NULL){
        while(LP->head != NULL){
            while(LP->head->S != NULL){
                SDL_BlitSurface(LP->head->S->head->square,NULL,screen,&LP->head->S->head->pos);
                LP->head->S->head = LP->head->S->head->next;
            }
            LP->head = LP->head->next;
        }
    }
}
