
#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "ADT/mesinkata.h"

#define IDX_UNDEF -1
#define CLUE '_'
#define KESEMPATAN 10

typedef struct {
    Word kalimat[100];
    int panjang;
} ListH;

int LenghtList(ListH L);

int savefile(ListH guessword, Word fileName);

FILE *StartWord(Word source);

ListH loadfile(Word source);

void ADVFL();

FILE* STARTF(char *source);

void CreateClue(Word *WSoal);
//untuk membuat sebuah list kosong dengan tampilan Mark sebanyak digit.

void CreateList(ListH *L);

void InsertLastH(ListH *L, Word kata);

void CreateWord(Word *Wsalah);
//prosedur untuk membuat sebuah list kosong dengan panjang IDX_UNDEF

int Ilustrasi(Word Wsalah);

void DeleteHuruf(Word *Wbenar, Word WSoal, int indeks);

void InsertHuruf(Word *Wbenar, Word WSoal, int indeks);

void UbahHuruf(Word *WSoal, char huruf, Word *Wsalah, Word *Wbenar);

void PrintKalimat(Word W);

int TampilanGame(Word Wbenar , Word Wsalah, int urutan, Word WSoal);

boolean IsOne(Word W);

boolean Ada(char huruf, Word Wsalah, Word Wbenar, Word WSoal);

void HangMan (int *skorhangman);

#endif