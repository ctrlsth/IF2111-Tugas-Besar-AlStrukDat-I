
#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../boolean.h"
#include "../ADT/mesinkata.h"

#define IDX_UNDEF -1
#define CLUE '_'
#define KESEMPATAN 10

typedef struct {
    Word kalimat[100];
    int panjang;
} ListH;

int LenghtList(ListH L);
//mengukur panjang dari sebuah list, entah list yg berada didalam file .txt ataupun tidak.

int savefile(ListH guessword, Word fileName);
//menyimpan sebuah Word kedalam List. Dipakai untuk menyimpan opsi jawaban/soal baru.

// FILE *StartWord(Word source);
//membaca 

// ListH loadfile(Word source);

void loadfile(ListH *SoalorJawaban);

// void ADVFL();

// FILE* STARTF(char *source);

void CreateClue(Word *WSoal);
//untuk membuat sebuah list kosong dengan tampilan Mark sebanyak digit.

void CreateList(ListH *L);

void InsertLastH(ListH *L, Word kata);

void CreateWord(Word *Wsalah);
//prosedur untuk membuat sebuah list kosong dengan panjang IDX_UNDEF

void Ilustrasi(Word Wsalah);

void DeleteHuruf(Word *Wbenar, Word WSoal, int indeks);

void InsertHuruf(Word *Wbenar, Word WSoal, int indeks);

void UbahHuruf(Word *WSoal, char huruf, Word *Wsalah, Word *Wbenar);

void PrintKalimat(Word W);

void TampilanGame(Word Wbenar , Word Wsalah, int urutan, Word WSoal);

boolean IsOne();

boolean Ada(char huruf, Word Wsalah, Word Wbenar, Word WSoal);

void HangMan (int *skorhangman);

#endif