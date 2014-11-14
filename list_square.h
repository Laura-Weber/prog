#ifndef LIST_SQUARE_H
#define LIST_SQUARE_H


#include "defs.h"
typedef struct square{

    /*position de chaque carré dans l'objet */
    unsigned int x;
    unsigned int y;

    struct square * next;
}square;

typedef struct list_square{
    square *first_square;
}list_square;

list_square * creat_list_square();
void add_square (list_square * LS, int x,int y);

#endif // LIST_SQUARE_H
