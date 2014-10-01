#include "list_piece.h"

list_piece empty_list (void)
{
  return NULL;
}

list_piece add_piece(list_piece L, square S)
{
  list_piece new_l = empty_list();
  new_l = (list_piece)malloc(sizeof(struct list_piece_ptr));
  new_l->square = S;
  new_l->next = L;
  return new_l;
}

int nb_piece(list_piece P)
{
  int nb = 0;
  while(P->square != NULL){
    nb += 1;
  }
  return nb;
}

void up_piece(list_piece P)
{
  while (P->square != NULL){
    P->square->y -= 1;
    P->square = P->square->next;
  }
}

void down_piece(list_piece P)
{
  while (P->square != NULL){
    P->square->y += 1;
    P->square = P->square->next;
  }
}

void up_piece(list_piece P)
{
  while (P->square != NULL){
    P->square->y -= 1;
    P->square = P->square->next;
  }
}

void right_piece(list_piece P)
{
  while (P->square != NULL){
    P->square->x += 1;
    P->square = P->square->next;
  }
}

void left_piece(list_piece P)
{
  while (P->square != NULL){
    P->square->x -= 1;
    P->square = P->square->next;
  }
}

void creat_list_piece(list_piece P)
{
  FILE * fichier;
  int pos_x = 0;
  int pos_y = 0;
  int caractereActuel;

  fichier = fopen("pentomino.txt", "r+w");

  if(fichier != NULL){
    while(caractereActuel != EOF){
      caractereActuel = fgetc(fichier);
	if (caractereActuel == '#'){
	  P->square = new_square(P->square, pos_x, pos_y);
	  pos_x += 1;
	}
	if (caractereActuel == '\n'){
	  pos_y += 1;
	  pos_x = 0;
	}
	if (caractereActuel = '\n\n'){
	  P = P->next;
	  pos_x = 0;
	  pos_y = 0;
	}
      }
      fclose(fichier);
    }else{
      printf("erreur fichier vide\n");
	}

list_piece rotate_r(list_piece P)
{
  while(P->square != NULL){
    if(P->square->y == 0){
  	p->square->y = P->square->x;
  	P->square->x = 3;
    }
    if(P->square->y == 1){
  	p->square->y = P->square->x;
  	P->square->x = 2;
    }
    if(P->square->y == 2){
    	p->square->y = P->square->x;
    	P->square->x = 1;
    }
    if(P->square->y == 3){
    	p->square->y = P->square->x;
    	P->square->x = 0;
    }
  P = P->next;
  }
}
