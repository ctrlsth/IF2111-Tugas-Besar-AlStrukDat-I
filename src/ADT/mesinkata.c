#include "mesinkata.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

// #define NMax 50
// #define BLANK ' '

/*
typedef struct
{
   char TabWord[NMax]; // container penyimpan kata, indeks yang dipakai [0..NMax-1]
   int Length;
} Word;
*/

/* State Mesin Kata */
boolean EndWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == BLANK)
    {
        ADV();
    }
}

void STARTWORD(char *textfile)
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START(textfile);
    IgnoreBlanks();
    if (CC == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    if (CC == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((CC != MARK) && (CC != BLANK) && (i < NMax))
    {
        currentWord.TabWord[i] = CC;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

Word GetCWord()
/* Mengembalikan currentWord
   I.S.  : currentWord sembarang */
{
    return currentWord;
}

Word toWord(char *someString)
/* Mengubah type String menjadi type Kata
   I.S. : string masukan bisa kosong */
{
    Word converted;
    int i = 0;
    while (someString[i] != '\0' && someString[i] != ' ')
    {
        converted.TabWord[i] = someString[i];
    }
    converted.Length = i;

    return converted;
}

boolean compareWord(Word kata1, char *kata2)
/* Membandingkan sebuah word dengan sebuah sting
   True     : Jika string dan kata sama,
   False    : Jika berbeda */
{
    if (kata1.Length == strLength(kata2))
    {
        int i = 0;
        while (i < kata1.Length)
        {
            if (kata1.TabWord[i] != kata2[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
    return false;
}

int strLength(char *kata)
/* Mengembalikan panjang suatu string kata */
{
    int i = 0;
    while (kata[i] != '\0')
    {
        i++;
    }
    return i;
}