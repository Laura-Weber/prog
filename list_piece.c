#include "list_piece.h"

list_piece empty_list (void)
{
  list_piece racine = malloc(sizeof(* racine));
  racine->prec = racine;
  racine->next = racine;
  return racine;
}

void add_piece_before(list_piece L, list_square S)
{
  list_piece new_l ;
  new_l = malloc(sizeof(*list_piece));
  new_l->square = S;
  new_l->prec = L->prec;
  new_l->suiv = L;
  L->prec->suiv = new_l;
  L->prec = new_l;
}

void add_piece_after(list_piece L, list_square S)
{
  list_piece new_l;
  new_l = malloc(sizeof(*list_piece));
  new_l->square = S;
  new_l->prec = L;
  new_l->suiv = L->suiv;
  L->suiv->prec = new_l;
  L->suiv = new_l;
}

void supp_piece(list_piece P)
{
  P->prec->suiv = P->suiv;
  P->suiv->prec = P->prec;
  free(P);
}

void supp_head_piece (list_piece racine)
{
  if(racine->suiv != racine){
  	supp_piece(racine->suiv);;
  }
}

void supp_end_piece (list_piece racine)
{
  if(racine->prec != racine){
  	supp_piece(racine->prec);;
  }
}

void add_head_piece(list_piece racine, square S)
{
  add_piece_after(racine, S);
}

void add_end_piece(list_piece racine, square S)
{
  add_piece_before(racine, S);
}

list_piece head_piece(list_piece racine)
{
  if(racine->suiv != racine){
  	return racine->suiv;
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

void free_list_piece(list_piece P)
{
  list_piece tmp, cur;
  for(tmp = P->suiv; tmp != P; tmp = cur){
  	cur = tmp->suiv;
  	free(tmp);
  }
  free(P);
  P = NULL;
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

list_piece creat_list_piece()
{
  list_piece P = empty_list;
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
	  P = add_piece(P,S);
	  pos_x += 1;
	  caractereActuel = fgets(fichier);
	}else{
	  if (caractereActuel == '\n'){
	    pos_y += 1;
	    pos_x = 0;
	    caractereActuel = fgetc(fichier);
	    if (caractereActuel = '\n\n'){
	      P = P->next;
	      pos_x = 0;
	      pos_y = 0;
	      caractereActuel = fgetsc(fichier);
	    }
	  }
	}
      }
      fclose(fichier);
    }else{
      printf("erreur fichier vide\n");
	}

list_piece rotate_r(list_piece P)
{
  while(P->square != NULL){
    if(P->square->x == 0){
  	p->square->x = P->square->y;
  	P->square->y = 3;
    }
    if(P->square->x == 1){
  	p->square->x = P->square->y;
  	P->square->y = 2;
    }
    if(P->square->x == 2){
    	p->square->x = P->square->y;
    	P->square->y = 1;
    }
    if(P->square->x == 3){
    	p->square->x = P->square->y;
    	P->square->y = 0;
    }
  P->square = P->square->next;
  }
}

list_piece rotate_l(list_piece P)
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
  P->square = P->square->next;
  }
}
