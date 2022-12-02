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
/* Membuat matriks node */

void create_linked_list_matrix(List *head, int rows, int cols, int headrow, int headcols);
/* Membuat list linked matriks*/

void createsnake(List* head,int headrow, int headcols, int *n);
/* Membuat snake pada matriks */

void movesnake(List* head, char move, int *n);
/* membuat ular bergerak pada matriks linked list */

void MakeFood(List head, addressNode *food, int n_row, int n_cols);
/*menentukan lokasi makanan pada matriks secara random*/

void SummonFood(List *head, int n_row, int n_cols);
/*memasukan makanan ke matriks*/

boolean isFood(List head,int n_row, int n_cols);
/*memeriksa apakah ada makanan pada matriks*/

boolean isNabrak(List head, char input);
/*Memeriksa apakah ular menabrak obstacle*/

boolean isNabrakBody(List head, char input);
/*Memeriksa apakah ular menabrak badan*/

boolean isNabrakMeteor(List head, char input);
/*memeriksa apakah ular menabrak meteor yang masih panas*/

void MakeMeteor(List head, addressNode *meteor,int n_row, int n_cols);
/* menentukan lokasi meteor pada matriks secara random */

void SummonMeteor(List *head, boolean* end, int *n, int n_row, int n_cols);
/* memasukan meteor ke matriks */

void MeteorDisappear(List *head, int n_row, int n_cols);
/* menghilangkan meteor yang sudah tidak panas pada matriks */

char *makebody(int n);
/* membentuk badan pada ular  */

boolean isNotMoveable(List head);
/*Mengecek apakah ular sudah tidak bisa bergerak*/


void makeobstacle(List head, addressNode *obstacle,int n_row, int n_cols);
/* menentukan lokasi obstacle pada matriks secara random  */

void summonobstacle(List* head, int count,int n_row, int n_cols);
/* memasukan meteor ke matriks */

#endif