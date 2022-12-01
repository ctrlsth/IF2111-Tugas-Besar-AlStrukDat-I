#ifndef towerOfHanoi_H
#define towerOfHanoi_H


#include "../boolean.h"
#include "../src/ADT/stack.h"

void CreateTower(Stack *S, int tumpukan);

void printStack(Stack S1, Stack S2, Stack S3, int tumpukan);

void printDasar(char a, int tumpukan, int panjang);

void printPiring(Stack S, int i, int tumpukan);

int piringLength(Word kata);

boolean isTowerFull(Stack S, int tumpukan);

boolean isStackMoveable(Stack S1, Stack S2,int tumpukan);

void MovePiringan(Stack* S1, Stack *S2, int tumpukan, char a, char b, boolean * piringan_moved);

boolean isTowerFinished(Stack S3, int tumpukan);

int FinalScore(int turn, int tumpukan);

void towerOfHanoi(int *score);

#endif