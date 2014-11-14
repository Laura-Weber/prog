#ifndef LEVEL_H
#define LEVEL_H


#include "defs.h"

list_piece * creat_lvl(char * road, piece * board);
void blitt_piece(list_piece *LP, piece *board, SDL_Surface * screen);

#endif //LEVEL_H

