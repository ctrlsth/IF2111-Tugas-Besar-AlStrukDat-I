#ifndef linkedlist_H
#define linkedlist_H

#include "../boolean.h"
#include "mesinkata.h"
#define KNil NULL

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

void create_linked_list_matrix(List *head, int rows, int cols, int headrow, int headcols, int *n);

void display_matrix(List head);

void movesnake(List* head, char move, int *n);

void MakeFood(List head, addressNode *food);

void SummonFood(List *head);

boolean isFood(List head);

boolean isNabrak(List head, char input);

boolean isNabrakMeteor(List head, char input);

void MakeMeteor(List head, addressNode *meteor);

void SummonMeteor(List *head, boolean* end, int *n);

void MeteorDisappear(List *head);

char *makebody(int n);

void makeobstacle(List head, addressNode *obstacle);

void summonobstacle(List* head, int count);

#endif