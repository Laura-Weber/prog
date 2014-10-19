#ifndef DEFS_H
#define DEFS_H

/****************************/
/* WEBER Laura, SCHMITT Lea */
/* L2 info                  */
/* defs.c                   */
/****************************/

/**************************************/
/* Useful library inclusion           */
/**************************************/

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "list_square.h"
#include "list_piece.h"

/**************************************/
/* Constante definition               */
/**************************************/

#define BLOC_SIZE 12
#define SCREEN_WIDTH  900
#define SCREEN_HEIGHT 600

enum {place, empty_p};

int again;
int intro;
int gameover;
int win;
int play;


#endif // DEFS_H
