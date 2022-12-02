#ifndef linkedlist_H
#define linkedlist_H

#include "../boolean.h"
#include "mesinkata.h"

// #define Nil NULL

typedef char* infotype;
typedef struct MatrixNode_ *addressNode;
typedef struct MatrixNode_{
    infotype info;
    addressNode next_row;
    addressNode prev_row;
    addressNode next_col;
    addressNode prev_col;
    addressNode next;
    addressNode prev;
}MatrixNode;

typedef struct {
    addressNode zero;
	addressNode First;
    addressNode Last;
}List;

MatrixNode* create_node();
/* Membuat node */

void create_linked_list_matrix(List *head, int rows, int cols, int headrow, int headcols);
/**/

void createsnake(List* head,int headrow, int headcols, int *n);


void display_matrix(List head);

void movesnake(List* head, char move, int *n);

void MakeFood(List head, addressNode *food, int n_row, int n_cols);

void SummonFood(List *head, int n_row, int n_cols);

boolean isFood(List head,int n_row, int n_cols);

boolean isNabrak(List head, char input);

boolean isNabrakBody(List head, char input);

boolean isNabrakMeteor(List head, char input);

void MakeMeteor(List head, addressNode *meteor,int n_row, int n_cols);

void SummonMeteor(List *head, boolean* end, int *n, int n_row, int n_cols);

void MeteorDisappear(List *head, int n_row, int n_cols);

char *makebody(int n);

boolean isNotMoveable(List head);

void makeobstacle(List head, addressNode *obstacle,int n_row, int n_cols);

void summonobstacle(List* head, int count,int n_row, int n_cols);

#endif