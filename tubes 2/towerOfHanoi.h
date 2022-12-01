#ifndef towerOfHanoi_H
#define towerOfHanoi_H

#include <stdio.h>
#include "boolean.h"
#include "../src/ADT/stack.h"


boolean finalGame(Stack S);

void showTiang(Stack S1, Stack S2, Stack S3);

void piringan(Stack S, int x, int wmax);

void proceedTiang(Stack *S1, Stack *S2);

void towerOfHanoi();

#endif