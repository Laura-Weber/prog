/****************************/
/* WEBER Laura, SCHMITT Lea */
/* L2 info                  */
/* main.c                   */
/****************************/

/**************************************/
/* Useful library inclusion           */
/**************************************/

#include "defs.h"

int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL, *menu = NULL, *game = NULL;
    SDL_Rect pos_menu;
    SDL_Event event;
    Dlist_piece piece = NULL;


    int continuer = 1;
    play = 0;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(SDL_LoadBMP("pentomino.bmp"), NULL);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("pentomino", NULL);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(SDL_LoadBMP("pentomino.bmp"), NULL);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("pentomino", NULL);

    while (continuer)
    {
        menu = SDL_LoadBMP("Press_Start.bmp");
        pos_menu.x = 0;
        pos_menu.y = 0;
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
                    play = 1;
            }
        }

        // Effacement de l'écran
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        SDL_BlitSurface(menu, NULL, screen, &pos_menu);
        SDL_Flip(screen);
    }
    piece = creat_list_piece();
    while(play){
        //blitt_piece(piece, screen);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                play = 0;
                break;
            case SDL_KEYDOWN:
            switch (event.key.keysym.sym){
                case SDLK_q:
                case SDLK_ESCAPE:
                    play = 0;
            }
        }

        // Effacement de l'écran
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(game, NULL, screen, &pos_menu);
        SDL_Flip(screen);
    }

    SDL_FreeSurface(menu);
    SDL_Quit();

    return EXIT_SUCCESS;
}

