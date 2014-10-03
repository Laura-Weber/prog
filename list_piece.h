#ifndef LIST_PIECE_H
#define LIST_PIECE_H

#include "defs.h"

typedef struct piece_ptr{
  piece square;
  struct piece_ptr * next;
} *list_piece;

#endif /* LIST_PIECE_H */
 
