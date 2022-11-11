#ifndef __MARVELSNAP__
#define __MARVELSNAP__

#include "../ADT/array.h"
#include "RNG.h"
#include <stdio.h>

typedef struct{
    int Energy;
    int Power;
} Card;

typedef struct{
    Card Hand[10];
    int Neff;
} ArrayCard;


typedef struct{
    int kekuatan[4];
    int Neff;
} ArrayInt;

void MakeArrayCard(ArrayCard* arraycard);

void MakeArrayInt(ArrayInt* arrayint);

void InsertCardAt(ArrayCard* array, Card el, int i);

void SetIntAt(ArrayInt *array, int el, int i);

void DeleteCardAt(ArrayCard *array, int i, Card *el);

Card randomCard();

void insertRandomCard(ArrayCard* array);

int CardEnergy();

int CardPower(int cardEnergy);

void PrintArena(ArrayInt Arena1Player1, ArrayInt Arena2Player1, ArrayInt Arena3Player1,ArrayInt Arena1Player2, ArrayInt Arena2Player2, ArrayInt Arena3Player2);

void MARVELSNAP();

void PlayerTurn(int* Energyturn, boolean* pemainNow ,boolean* pemainThen, ArrayCard *Player, ArrayInt* Arena1Player, ArrayInt* Arena2Player, ArrayInt* Arena3Player);

void PrintCard(ArrayCard Player);

void skorakhir(ArrayInt Arena1Player1, ArrayInt Arena2Player1, ArrayInt Arena3Player1,ArrayInt Arena1Player2, ArrayInt Arena2Player2, ArrayInt Arena3Player2);

void COMMANDGAME();

void PLAYGUIDE();

#endif