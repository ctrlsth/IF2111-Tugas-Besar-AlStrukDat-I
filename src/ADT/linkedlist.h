#ifndef linkedlist_H
#define linkedlist_H

#include "../boolean.h"
#include "mesinkata.h"
#define Nil NULL

typedef char* infotype;
typedef struct MatrixNode_ *address;
typedef struct MatrixNode_{
    infotype info;
    address next_row;
    address prev_row;
    address next_col;
    address prev_col;
    address next;
    address prev;
}MatrixNode;

typedef struct {
    address zero;
	address First;
    address Last;
}List;

MatrixNode* create_node();

void create_linked_list_matrix(List *head, int rows, int cols, int headrow, int headcols, int *n);

void display_matrix(List head);

void movesnake(List* head, char move, int *n);

void MakeFood(List head, address *food);

void SummonFood(List *head);

boolean isFood(List head);

boolean isNabrak(List head, char input);

boolean isNabrakMeteor(List head, char input);

void MakeMeteor(List head, address *meteor);

void SummonMeteor(List *head, boolean* end, int *n);

void MeteorDisappear(List *head);

char *makebody(int n);

void makeobstacle(List head, address *obstacle);

void summonobstacle(List* head, int count);

#endif