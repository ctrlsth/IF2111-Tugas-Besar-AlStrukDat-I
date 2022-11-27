#ifndef __HANGMAN__
#define __HANGMAN__

#include "../boolean.h"
#include "../ADT/array.h"

#define LINE  '_'
#define KESEMPATAN 10

void CreateWord (Word *LSoal, int digit, boolean mark);

void ListofWord(TabWord* array, boolean *openSuccess);

void menuawal(TabWord*array,boolean* game_started);

void savelist(TabWord array);

void TampilanGaris(int count_salah);

void SetElmt(Word *Lbenar , char huruf, int indeks);

void DigitBenar(Word LSoal, char huruf, Word* Lsalah, Word* Lbenar, int *count_salah, int *point);

void PrintList(Word L, boolean benar);

void TampilanGame(Word Lbenar ,Word Lsalah, int urutan, int count_salah);

boolean isExist (char huruf, Word Lsalah);

boolean isMark(Word Lbenar);

boolean IsFinished (int count_salah);

void TampilanKalah(int count_salah, int point, Word LJawaban);

void hangman();

#endif
