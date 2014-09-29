/*Weber Laura && Schmitt*/
/*File that contains the main*/

#include "define.h"
 
int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    int caractereActuel = 0;
    SDL_Surface * ecran = NULL, *rectangle = NULL;
    SDL_Rect position;

    SDL_Init(SDL_INIT_VIDEO); 
 
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 8, 8, 8, 0, 0, 0, 0);
    position.x = 0;
    position.y = 0;

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));
    SDL_Flip(ecran);

    SDL_WM_SetCaption("pentomino", NULL);
    fichier = fopen("pentomino.txt", "r+w");
    
    if(fichier != NULL){
      
      rewind(fichier);
      while(caractereActuel != EOF){
	caractereActuel = fgetc(fichier);
	if (caractereActuel == '#'){
	  SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 0, 0)); 
	  SDL_BlitSurface(rectangle, NULL, ecran, &position); 
	  position.x += 8;
	}
	if (caractereActuel == '\n'){
	  position.y += 8;  
	  position.x = 0;
	}
      }
      fclose(fichier);
    }

    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
 
    SDL_Quit(); 
 
    return EXIT_SUCCESS;
}
 
