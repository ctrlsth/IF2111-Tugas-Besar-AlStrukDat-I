/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "mesinkarakter.h"

#define NMax 200
#define BLANK ' '

typedef struct
{
   char TabChar[NMax];
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;
extern Word currentCommand;

void STARTWORD(char* txtfile, boolean *openSuccess);
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

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = EOF */

void STARTCMD(boolean inputGame);
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, currentCommand adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVCMD(boolean inputGame);
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentCommand adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure COPYCMD */

void COPYCMD();
/* Mengakuisisi command, menyimpan dalam currentCommand
   I.S. : CC adalah karakter pertama dari kata
   F.S. : currentCommand berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void COPYGAME();
/* Mengakuisisi nama game, menyimpan dalam currentCommand
   I.S. : CC adalah karakter pertama dari kata
   F.S. : currentCommand berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void IgnoreBlanksCMD();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

Word toWord(char *someString);
/* Mengubah type String menjadi type Kata
   I.S. : string masukan bisa kosong */

char* toString(Word kata);
/* Mengubah type Word menjadi String */

int toInt(Word kata);
/* Mengupah type Word menjadi Integer */

boolean isNumber(Word kata);
/* Melihat apakah masukan merupakan angka atau bukan */

boolean compareWord(Word kata1, char *kata2);
/* Membandingkan sebuah word dengan sebuah sting
   True     : Jika string dan kata sama,
   False    : Jika berbeda */

boolean compare2Word(Word kata1, Word kata2);
/* Membandingkan 2 buah word
   True     : Jika kedua word sama,
   False    : Jika berbeda */

int strLength(char *kata);
/* Mengembalikan panjang suatu string kata */

void printWord(Word Kata);
/* Menampilkan isi kata pada layar */

void binSep(Word Kata, Word *Kata1, Word *Kata2, char separator);

void UPPER(Word *Kata);

#endif
