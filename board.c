#include "defs.h"

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

void affichage fenêtre()
{
  couleur couleurContour = {255, 0, 0};
  point p1 = {10, 10};
  point p2 = {100, 100};
}
