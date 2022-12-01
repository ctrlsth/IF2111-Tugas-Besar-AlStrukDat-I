#ifndef SNAKE_ON_METEOR_H
#define SNAKE_ON_METEOR_H

#include "../ADT/linkedlist.h"
#include "../boolean.h"
#include "../console.h"


void snakeart();

void printArena(List matriks, int n_row, int n_cols);

void snakeonmeteor(int *score);

void setGameSnake(List *head, int* count_row, int*count_cols, int *n);

#endif