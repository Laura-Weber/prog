/****************************/
/* WEBER Laura, SCHMITT Lea */
/* L2 info                  */
/* main.c                   */
/****************************/

/**************************************/
/* Useful library inclusion           */
/**************************************/

#include "defs.h"

SDL_Surface * screen;
SDL_Rect pos_screen;
piece* piece_select;
piece * board;
list_piece * a_jouer;
int continuer;

void rotate_r()
{
    if(piece_select->rotation_actual == 3){
        piece_select->rotation_actual = 0;
    }else{
        if(piece_select->rotation_actual == 7){
            piece_select->rotation_actual = 4;
        }else{
            piece_select->rotation_actual += 1;
        }
    }
}

void rotate_l()
{
    if(piece_select->rotation_actual > 4){
        piece_select->rotation_actual -= 1;
    }else{
        if(piece_select->rotation_actual == 4){
            piece_select->rotation_actual = 7;
        }else{
            if(piece_select->rotation_actual > 0){
                piece_select->rotation_actual -= 1;
            }else{
                piece_select->rotation_actual = 3;
            }
        }
    }
}

void sym()
{
  if(piece_select->rotation_actual < 4){
    piece_select->rotation_actual += 4;
  }else{
    piece_select->rotation_actual -= 4;
  }
}


void select_piece(int x,int y)
{
    square * square_actu;
    piece * piece_actu = a_jouer->first_piece;
    int trouver = 0;
    while(piece_actu && trouver == 0){
        square_actu = piece_actu->rotate_tab[piece_actu->rotation_actual]->first_square;

        while(square_actu && trouver == 0){
            if( ( x >= piece_actu->x + (square_actu->x ) *BLOC_SIZE ) && ( (x <= piece_actu->x + (square_actu->x+1) *BLOC_SIZE ) )){
                if( ( y >= piece_actu->y + (square_actu->y) *BLOC_SIZE ) && ( (y <= piece_actu->y + (square_actu->y+1) *BLOC_SIZE ) )){

                    trouver = 1;
                    piece_select = piece_actu;
                    piece_select->sur_plateau = 0;

                }
            }
            square_actu = square_actu->next;
        }
        piece_actu = piece_actu->next;

    }
}

int win()
{
  piece * piece_actu = a_jouer->first_piece;

  while(piece_actu){
    if(piece_actu->sur_plateau == 0){
      return 0;
    }
    piece_actu = piece_actu->next;
  }
  return 1;
}

int x_on_board(int x)
{
    return ((int)(x/BLOC_SIZE)) * BLOC_SIZE;
}

int y_on_board(int y )
{
    return ((int)(y/BLOC_SIZE)) * BLOC_SIZE;
}

void place_on_board()
{
    piece * piece_actu = piece_select;
    if(piece_actu){
        piece_actu->x = x_on_board(piece_actu->x);
        piece_actu->y = y_on_board(piece_actu->y);
    }
    piece_select = NULL;
}

void play()
{

  piece_select = NULL;
  int play = 1;
  SDL_Surface *game = NULL;
  SDL_Event event;
  char * road = "2.txt";
  board = creat_piece();
  a_jouer = creat_lvl(road, board);
  game = SDL_LoadBMP("fd2.bmp");
  blitt_piece(a_jouer, piece_select, board, screen);
  SDL_BlitSurface(game, NULL, screen, &pos_screen);


  while(win() == 0 && play){
    SDL_WaitEvent(&event);
    switch(event.type){
        case SDL_QUIT:
                play = 0;
                break;

            case SDL_KEYDOWN:
            switch (event.key.keysym.sym){
                case SDLK_q: // need to press q
                case SDLK_ESCAPE:
                play = 0;
                break;

            }
            break;

            case SDL_MOUSEBUTTONDOWN:
                if(piece_select){
                    if (event.button.button == SDL_BUTTON_WHEELUP){
                        rotate_r();
                    }
                    if (event.button.button == SDL_BUTTON_WHEELDOWN){

                        rotate_l();
                    }

                }
                break;

            case SDL_MOUSEBUTTONUP:
                if ((event.button.button == SDL_BUTTON_RIGHT) && piece_select){
                        sym();
                    }
                if(event.button.button == SDL_BUTTON_LEFT){
                    if (piece_select){
                        place_on_board();
                    }else {
                        select_piece(event.button.x, event.button.y);
                    }
                }
                break;

                case SDL_MOUSEMOTION:
                    if (piece_select){
                        move_piece(piece_select, event.button.x - BLOC_SIZE * 2, event.button.y);
                    }
                    break;
    }

    SDL_BlitSurface(game, NULL, screen, &pos_screen);
    blitt_piece(a_jouer, piece_select, board, screen);
    SDL_Flip(screen);
  }

  SDL_FreeSurface(game);

}

void menu()
{
  SDL_Event event;
  SDL_Surface * menu = NULL;
  continuer = 1;
  while (continuer)
    {
      menu = SDL_LoadBMP("Press_Start.bmp");
      pos_screen.x = 0;
      pos_screen.y = 0;
      SDL_WaitEvent(&event);
      switch(event.type)
        {
	case SDL_QUIT:
	  continuer = 0;
	case SDL_KEYDOWN:
	  switch (event.key.keysym.sym){
	  case SDLK_ESCAPE:
	    continuer = 0;
	    break;
	  case SDLK_RETURN:
	    continuer = 0;
	  }
        }

      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
      SDL_BlitSurface(menu, NULL, screen, &pos_screen);
      SDL_Flip(screen);
    }
  SDL_FreeSurface(menu);
}



int main(int argc, char *argv[])
{

  pos_screen.x = 0;
  pos_screen.y = 0;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetIcon(SDL_LoadBMP("pentomino.bmp"), NULL);
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("pentomino", NULL);

  menu();
  play();
  SDL_FreeSurface(screen);
  SDL_Quit();
  exit(EXIT_SUCCESS);
}




