/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "mesinkarakter.h"

#define NMax 100 // Harus diubah
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord1;
extern Word currentWord2;
extern Word currentWordFile;

void IgnoreBlanks(boolean CMD);
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void C_IgnoreBlank();

void STARTWORD();
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void COPYWORD();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void STARTCMD();
void ADVCMD();
void COPYCMD();

void STARTWORDFILE(char *c);
void ADVWORDFILE();
void COPYWORDFILE();

int KataInt(Word k);

Word GetCWord1();
/* Mengembalikan currentWord
   I.S.  : currentWord sembarang */

Word GetCWord2();

Word addtxt(Word filename);

Word toWord(char* someString);
/* Mengubah type String menjadi type Kata 
   I.S. : string masukan bisa kosong */

boolean compareWord(Word kata1, char* kata2);
/* Membandingkan sebuah word dengan sebuah sting
   True     : Jika string dan kata sama, 
   False    : Jika berbeda */

int strLength(char *kata);
/* Mengembalikan panjang suatu string kata */

void printWord(Word Kata);

char* toString(Word Kata);

char* strConcat(char* s1, char* s2);

void IgnoreBlank();
void CMD_STARTKATA();
void CMD_ADVKATA();
void CMD_COPYWORD();


#endif