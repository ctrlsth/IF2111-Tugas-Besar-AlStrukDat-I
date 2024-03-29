#ifndef __HANGMAN__
#define __HANGMAN__

#include "../boolean.h"
#include "../ADT/array.h"

#define LINE  '_'
#define KESEMPATAN 10

void CreateWord (Word *LSoal, int digit, boolean mark);

void ListofWord(TabWord* arrayWord, TabWord*arraySoal, boolean *openSuccess);

void menuawal(TabWord*arrayWord,TabWord *arraySoal,boolean* game_started);

void savelist(TabWord arrayWord, TabWord arraySoal);

void TampilanGaris(int count_salah);

void SetElmt(Word *Lbenar , char huruf, int indeks);

void DigitBenar(Word LSoal, char huruf, Word* Lsalah, Word* Lbenar, int *count_salah, int *point);

void PrintList(Word L, boolean benar);

void TampilanGame(Word Lbenar ,Word Lsalah, Word Lsoal,int urutan, int count_salah, int count_word_guessed);

boolean isExist (char huruf, Word Lsalah);

boolean isMark(Word Lbenar);

boolean IsFinished (int count_salah, TabWord array);

void TampilanKalah(int count_salah, int point, Word LJawaban);

void HangMan(int *score);

#endif