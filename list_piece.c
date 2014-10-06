/******************************************************************/
/* list_piece.c                                                   */
/* Léa SCHMITT, Laura Weber                                       */
/******************************************************************/

/**************************************/
/* Useful library inclusion           */
/**************************************/

#include "list_piece.h"
#include "square.h""
#include "defs.h"

/*******************************************************************/
/*             FUNCTION DEFINITION                                 */
/*******************************************************************/

list_piece empty_list (void)
{
  list_piece racine = malloc(sizeof(* racine));
  racine->prec = racine;
  racine->next = racine;
  return racine;
}
/////////////////////
//   add fuction   //
/////////////////////

void add_piece_before(list_piece L, list_square S)
{
  list_piece new_l ;
  new_l = malloc(sizeof(*new_l));
  new_l->square = S;
  new_l->prec = L->prec;
  new_l->next = L;
  L->prec->next = new_l;
  L->prec = new_l;
}

void add_piece_after(list_piece L, list_square S)
{
  list_piece new_l;
  new_l = malloc(sizeof(*new_l));
  new_l->square = S;
  new_l->prec = L;
  new_l->next = L->next;
  L->next->prec = new_l;
  L->next = new_l;
}

void add_head_piece(list_piece racine, list_square S)
{
  add_piece_after(racine, S);
}

void add_end_piece(list_piece racine, list_square S)
{
  add_piece_before(racine, S);
}

/////////////////////////
//     constructors    //
/////////////////////////

list_piece creat_list_piece()
{
  list_piece P = empty_list();
  list_square S = empty_square();
  FILE * fichier;
  int pos_x = 0;
  int pos_y = 0;
  int caractereActuel;

  fichier = fopen("pentomino.txt", "r+w");
  caractereActuel = fgetc(fichier);

  if(fichier != NULL){
    while(caractereActuel != EOF){
      	if (caractereActuel == '#'){
	  S = new_square(S, pos_x, pos_y);
	  add_piece_after(P,S);
	  pos_x += 1;
	  caractereActuel = fgetc(fichier);
	}else{
	  if (caractereActuel == '\n'){
	    pos_y += 1;
	    pos_x = 0;
	    caractereActuel = fgetc(fichier);
	    if (caractereActuel = '\n'){
	      P = P->next;
	      pos_x = 0;
	      pos_y = 0;
	      caractereActuel = fgetc(fichier);
	    }
	  }
	}
      }
      fclose(fichier);
    }else{
      printf("erreur fichier vide\n");
	}
  return P;
}

/////////////////////////////
//     Supp function       //
/////////////////////////////

void supp_piece(list_piece P)
{
  P->prec->next = P->next;
  P->next->prec = P->prec;
  free(P);
}

void supp_head_piece (list_piece racine)
{
  if(racine->next != racine){
    supp_piece(racine->next);;
  }
}

void supp_end_piece (list_piece racine)
{
  if(racine->prec != racine){
    supp_piece(racine->prec);;
  }
}

////////////////////////////
//    access functions    //
////////////////////////////

bool is_empty(list_piece racine)
{
  if(racine->next == racine && racine->prec == racine){
  	return true;
  }else{
  	return false;
  }  
}

list_piece head_piece(list_piece racine)
{
  if(racine->next != racine){
    return racine->next;
  }else{
    return NULL;
  }
}

list_piece end_piece(list_piece racine)
{
  if(racine->prec != racine){
    return racine->prec;
  }else{
    return NULL;
  }
}

////////////////////////////
//      free function     //
////////////////////////////

void free_list_piece(list_piece P)
{
  list_piece tmp, cur;
  for(tmp = P->next; tmp != P; tmp = cur){
    cur = tmp->next;
    free(tmp);
  }
  free(P);
  P = NULL;
}

//////////////////////////
//    move function     //
//////////////////////////

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

list_piece rotate_r(list_piece P)
{
  while(P->square != NULL){
    if(P->square->x == 0){
  	P->square->x = P->square->y;
  	P->square->y = 3;
    }
    if(P->square->x == 1){
  	P->square->x = P->square->y;
  	P->square->y = 2;
    }
    if(P->square->x == 2){
    	P->square->x = P->square->y;
    	P->square->y = 1;
    }
    if(P->square->x == 3){
    	P->square->x = P->square->y;
    	P->square->y = 0;
    }
  P->square = P->square->next;
  }
}

list_piece rotate_l(list_piece P)
{
  while(P->square != NULL){
    if(P->square->y == 0){
      P->square->y = P->square->x;
      P->square->x = 3;
    }
    if(P->square->y == 1){
      P->square->y = P->square->x;
      P->square->x = 2;
    }
    if(P->square->y == 2){
      P->square->y = P->square->x;
      P->square->x = 1;
    }
    if(P->square->y == 3){
      P->square->y = P->square->x;
      P->square->x = 0;
    }
    P->square = P->square->next;
  }
}

//////////////////////////
//    other function    //
//////////////////////////

int nb_piece(list_piece P)
{
  int nb = 0;
  while(P->square != NULL){
    nb += 1;
  }
  return nb;
}

void afficher_list(list_piece P)
{
  list_piece it;
  for ( it = P->suiv; it != P; it = it->suiv ){
    while(it->square != NULL){
    printf("(%d, %d)", it->square->x, it->square->y);
    it->square = it->square->next;
    }
  }
}
