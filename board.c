#include "defs.h"

void ColoriePixel (int x, int y, TCouleur C)
{

  if(!SDL_MUSTLOCK(fenetre) || SDL_LockSurface(fenetre) >= 0)
   {
    if(x>=0 && x<fenetre->w && y>=0 && y<fenetre->h)
     {
      Uint8 *pixmem32 = (Uint8*) fenetre->pixels  + y * fenetre->pitch + x * BytePP;
      *(Uint32 *)pixmem32 = SDL_MapRGB(fenetre->format, C.R, C.V, C.B);
     }
   }
   if(SDL_MUSTLOCK(fenetre)) 
    {
     SDL_UnlockSurface(fenetre);
    }
}

void dessine_segment(point p1, point p2)
{
  double dx = 0.0, dy = 0.0;
  int signe = 1;
  int x, y;

  if(p1.x == p2.x) // Segments verticaux
    {
      dy = p2.y - p1.y;
    }
  else
    {
      dy = (double)(p2.y - p1.y) / (p2.x - p1.x);
    }
  if(p1.y == p2.y) // Segments horizontaux
    {
      dx = p2.x - p1.x;
    }
  else
    {
      dx = (double)(p2.x - p1.x) / (p2.y - p1.y);
    }
  if(fabs(dx) >= fabs(dy)) // Parcours des colonnes
    {
      if(p2.x < p1.x)
	      {
      	  signe = -1;
      	}
      for(x=p1.x; x!=p2.x+signe; x+=signe)
      	{
      	  y = p1.y + (int) rint(dy*(x-p1.x));
      	  ColoriePixel(x, y, coul);
      	}
    }
  else // Parcours des lignes
    {
      if(p2.y < p1.y)
      	{
      	  signe = -1;
      	}
      for(y=p1.y; y!=p2.y+signe; y+=signe)
      	{
      	  x = p1.y + (int) rint(dx*(y-p1.y));
      	  ColoriePixel(x, y, coul);
      	}
    }  
}

void print_board()
{
  couleur couleurContour = {255, 0, 0};
  point p1 = {10, 10};
  point p2 = {100, 100};
}
