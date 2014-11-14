#include "defs.h"

list_piece * creat_lvl(char * road, piece * board)
{
  FILE * file = fopen(road, "r");
  board->rotate_tab[0] = creat_list_square();
  board->x = X_BOARD;
  board->y = Y_BOARD;
  int i = 0;
  char tab[][20] = {"bleu.bmp","bleuc.bmp","brun.bmp","jaune.bmp","orange.bmp","rose.bmp","rose2.bmp","rose3.bmp","rouge.bmp","vert.bmp","violet.bmp"};
  int caract;
  int x;
  int y;
  x =0;
  y = 0;
  int j = 50, k = 0;
  unsigned int nb_diese = 0;
  bool finish_board = false;
  list_piece * LP;
  piece * P = creat_piece();
  board->bitmap = SDL_LoadBMP("g2.bmp");
  list_square * LS = creat_list_square();

  if(file){

    LP = creat_list_piece();
    rewind(file);
    caract = fgetc(file);

    while (caract != EOF){

      if(caract == ' '){
	x += 1;
      }

      if(caract == '#'){
	x += 1 ;
	nb_diese += 1;
	if(!finish_board){
	  add_square(board->rotate_tab[0],x,y);
	}else{
	  add_square(LS,x,y);
	}
      }

      if(caract == '\n'){
	if(finish_board){
	  x = 0;
	}else{
	  x = 0;
	}
	if(nb_diese == 0 ){
	  if(!finish_board && board->rotate_tab[0]->first_square){
	    finish_board = true;
	    x = 0;
	    y = 0;
	  }else if(!finish_board ){
	    x = 0;
	    y = 0;
	  }
	  if(LS->first_square ){

	    x = 0;
	    y = 0;
	    P->rotate_tab[0] = LS;

	    P->bitmap = SDL_LoadBMP(tab[i]);

	    if(i == 10){
	      i = 0;
	    }else{
	      i++;
	    }
	    make_rotation(P);
	    add_piece(LP,P);
	    P = creat_piece();
	    LS = creat_list_square();
	  }
	}else{
	  y += 1;
	}
	nb_diese = 0;
      }
      caract = fgetc(file);
    }
    if(LS->first_square){
      if(LS->first_square){
	P->rotate_tab[0] = LS;
	add_piece(LP,P);
      }else{
	free(LS);
	free(P);
      }
    }

    fclose(file);
  }
  board->rotation_actual = 0;
  piece * temp = LP->first_piece;
  temp->x = 10;

  while(temp){
    if(k > 700){
        j = 500;
        k = 0;
    }
    temp->x += k;
    temp->y += j;
    k += 100;
    temp = temp->next;
  }
  return LP;
}

void blitt_piece(list_piece *LP, piece *board, SDL_Surface * screen)
{
  SDL_Rect pos;
  pos.h = BLOC_SIZE;
  pos.w = BLOC_SIZE;

  square *S = board->rotate_tab[LP->first_piece->rotation_actual]->first_square;

  while(S){

    pos.x = board->x + (S->x)*BLOC_SIZE;
    pos.y = board->y + (S->y)*BLOC_SIZE;

    SDL_BlitSurface(board->bitmap,NULL,screen,&pos);
    S = S->next;

  }

  piece * temp = LP->first_piece;

  while(temp){

    S = temp->rotate_tab[LP->first_piece->rotation_actual]->first_square;
    while(S){
      pos.x = temp->x + (S->x)*BLOC_SIZE;
      pos.y = temp->y + (S->y)*BLOC_SIZE;
      pos.x += BLOC_SIZE;
      SDL_BlitSurface(temp->bitmap,NULL,screen,&pos);
      S = S->next;

    }
    temp = temp->next;
  }
}

