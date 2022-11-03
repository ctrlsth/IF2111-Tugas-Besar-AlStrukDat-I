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
Word currentWord1;
Word currentWord2;

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

void PROMPT()
{
    
}

void STARTWORD(boolean PROMPT)
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, currentWord1 adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlanks();
    if (CC == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVWORD(PROMPT);
    }
}

void ADVWORD(boolean PROMPT)
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord1 adalah kata terakhir yang sudah diakuisisi,
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
        if (PROMPT)
        {
            COPYPROMPT();
        }
        else
        {
            COPYWORD();
        }
        IgnoreBlanks();
    }
}

void COPYWORD()
/* Mengakuisisi kata, menyimpan dalam currentWord1
   I.S. : CC adalah karakter pertama dari kata
   F.S. : currentWord1 berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((CC != MARK) && (CC != BLANK) && (i < NMax))
    {
        currentWord1.TabWord[i] = CC;
        ADV();
        i++;
    }
    currentWord1.Length = i;
}

void COPYPROMPT()
{
    int i = 0, j = 0;
    boolean passedBLANK = false;
    while ((CC != MARK) && (i+j+1 < NMax))
    {
        if (passedBLANK)
        {
            currentWord2.TabWord[j] = CC;
            ADV();
            j++;
        }
        else
        {
            if (CC == BLANK)
            {
                passedBLANK = true;
            }
            else
            {
                currentWord1.TabWord[i] = CC;
                ADV();
            }
            i++;
        }
    }
}

Word GetCWord1()
/* Mengembalikan currentWord1
   I.S.  : currentWord1 sembarang */
{
    return currentWord1;
}

Word GetCWord2()
{
    return currentWord2;
}

Word addtxt(Word filename)
/* Menambahkan extension .txt pada namafile */
{
    int i = filename.Length;
    filename.TabWord[i] = '.';
    filename.TabWord[i+1] = 't';
    filename.TabWord[i+2] = 'x';
    filename.TabWord[i+3] = 't';

    return filename;
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