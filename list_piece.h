#ifndef LIST_PIECE_H
#define LIST_PIECE_H

/******************************************************************/
/* list_piece.h                                                   */
/* Léa SCHMITT, Laura Weber                                       */
/******************************************************************/

/**************************************/
/* Useful library inclusion           */
/**************************************/

#include "defs.h"
#include "square.h"

/*******************/
/*    Structure    */
/*******************/

typedef struct piece_ptr{
  list_square square;
  struct piece_ptr * prec;
  struct piece_ptr * next;
} *list_piece;

/*******************************************************************/
/*             FUNCTION DEFINITION                                 */
/*******************************************************************/

list_piece empty_list (void);

/////////////////////
//   add fuction   //
/////////////////////

void add_piece_before(list_piece L, list_square S);
void add_piece_after(list_piece L, list_square S);
void add_head_piece(list_piece racine, list_square S);
void add_end_piece(list_piece racine, list_square S);

/////////////////////////
//     constructors    //
/////////////////////////

list_piece creat_list_piece();  

/////////////////////////////
//     Supp function       //
/////////////////////////////

void supp_piece(list_piece P);
void supp_head_piece (list_piece racine);
void supp_end_piece (list_piece racine);

////////////////////////////
//    access functions    //
////////////////////////////

list_piece head_piece(list_piece racine);
list_piece end_piece(list_piece racine);

////////////////////////////
//      free function     //
////////////////////////////

void free_list_piece(list_piece P);

//////////////////////////
//    move function     //
//////////////////////////

void up_piece(list_piece P);
void down_piece(list_piece P);
void up_piece(list_piece P);
void right_piece(list_piece P);
void left_piece(list_piece P);
list_piece rotate_r(list_piece P);
list_piece rotate_l(list_piece P);

//////////////////////////
//    other function    //
//////////////////////////

int nb_piece(list_piece P);

#endif /* LIST_PIECE_H */
 
