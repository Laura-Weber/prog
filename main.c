#include "defs.h"
 
int main(int argc, char *argv[])
{
    SDL_Surface * ecran = NULL, *rectangle = NULL;
    int continuer = 1;
    SDL_Rect position;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO); 
 
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 8, 8, 32, 0, 0, 0, 0);
    position.x = 0;
    position.y = 0;
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_Flip(ecran);

    SDL_WM_SetCaption("pentomino", NULL);
           
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
	  case SDL_QUIT:
            continuer = 0;
	  case SDL_KEYDOWN:
	    switch (event.key.keysym.sym){
	      case SDLK_ESCAPE:
	      case SDLK_q:
	        continuer = 0;
	        break;
	  }
        }
    }
 
    SDL_Quit(); 
 
    return EXIT_SUCCESS;
}
 
