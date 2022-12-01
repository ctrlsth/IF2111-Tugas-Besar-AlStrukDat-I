#include "mesinkata.h"
#include <stdlib.h>
#include <stdio.h>

// #define NMax 50
// #define BLANK ' '

/* State Mesin Kata */
boolean EndWord;
Word currentWord1;
Word currentWord2;
Word currentWordFile;

void IgnoreBlanks(boolean CMD)
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
<<<<<<< Updated upstream
    while (CC == BLANK)
    {
        if (CMD)
        {
            ADVCMD();
        }
        else
        {
            ADV();
        }
    }
}

void IgnoreBlank()
{
    while ((CC == BLANK) && (CC != MARKCMD))
    {
        ADV();
    }
}

void CMD_STARTKATA(){
    STARTC();
    IgnoreBlank();
    if (CC == MARKCMD)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CMD_COPYWORD();
=======
    loadstart(txtfile, openSuccess);
    if(*openSuccess){
        IgnoreBlanks();
        if (CC == EOF)
        {
            EndWord = true;
        }
        else
        {
            EndWord = false;
            ADVWORD();
        }
>>>>>>> Stashed changes
    }
}

void CMD_ADVKATA()
{
    IgnoreBlank();
    if (CC == MARKCMD)
    {
        EndWord = true;
    }
    else
    {
        CMD_COPYWORD();
    }
}

void CMD_COPYWORD()
{
    int i = 0;
    while ((CC != MARKCMD) && (CC != BLANK))
    {
        currentWord1.TabWord[i] = CC;
        ADVC();
        i++;
    }
    currentWord1.Length = i;
}

void C_IgnoreBlank()
{
    while ((CC == BLANK) || (CC == MARKCMD))
    {
        ADVFILE();
    }
}

void STARTWORD()
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, currentWord1 adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlanks(false);
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
        COPYWORD();
        IgnoreBlanks(false);
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

void STARTCMD()
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, currentWord1 adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlanks(true);
    if (CC == MARKCMD)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVCMD();
    }
}

void ADVCMD()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord1 adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    if (CC == MARKCMD)
    {
        EndWord = true;
    }
    else
    {
        COPYCMD();
        IgnoreBlanks(true);
    }
}

void COPYCMD()
{
    int i = 0;
    while ((CC != MARKCMD) && (CC != BLANK) && (i < NMax))
    {
        currentWord1.TabWord[i] = CC;
        ADV();
        i++;
    }
    currentWord1.Length = i;

    if (CC == BLANK)
    {
        i = 0;
        ADV();
        while ((CC != MARKCMD) && (CC != BLANK) && (i < NMax))
        {
            currentWord2.TabWord[i] = CC;
            ADV();
            i++;
        }
        currentWord2.Length = i;
    }
}

void STARTWORDFILE(char *c)
{
    STARTFILE(c);
    C_IgnoreBlank();
    if (CC == EOF) {
        EndWord = true;
    } else /* cc != MARK */ {
        EndWord = false;
        ADVWORDFILE();
    }
    C_IgnoreBlank();
}

void ADVWORDFILE()
{
    C_IgnoreBlank();
    if (CC == EOF) {
        EndWord = true;
    } else /* cc != MARK */ {
        COPYWORDFILE();   
    }
    C_IgnoreBlank();
}

void COPYWORDFILE()
{
    int i = 0;
    while ((CC != MARKCMD) && (CC != EOF))
    {
        currentWord1.TabWord[i] = CC;
        ADVFILE();
        i++;
    }
    currentWord1.Length = i;
}

int KataInt(Word k)
{
    int i;
    char huruf;
    int value = 0;
    for (i=0;i<k.Length;i++){
        huruf = k.TabWord[i];
        value = (value*10) + (huruf - '0');
    }
    return value;
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
    filename.TabWord[i + 1] = 't';
    filename.TabWord[i + 2] = 'x';
    filename.TabWord[i + 3] = 't';

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

void printWord(Word Kata)
{
    int i;
    for (i = 0; i < Kata.Length; i++)
    {
        printf("%c", Kata.TabWord[i]);
    }
}

char* toString(Word Kata){
    int i;
    char* word;
    word = (char*) malloc ((Kata.Length+1) * sizeof(char*));
    for(i=0;i<Kata.Length;i++){
        word[i] = Kata.TabWord[i];
    }
    word[i] = '\0';
    return word;
}

char* strConcat(char* s1, char* s2){
    int i,j;
    char* s3;
    s3 = (char*) malloc ((strLength(s1)+strLength(s2)+1) * sizeof(char*));
    for(i=0;i<strLength(s1);i++){
        s3[i] = s1[i];
    }
    for(j=0;j<strLength(s2);j++){
        s3[i] = s2[j];
        i++;
    }
    s3[i] = '\0';
    return s3;
}

boolean strcompare(char *kata1, char *kata2){
    boolean same = false;
    int i = 0;
    if(strLength(kata1) == strLength(kata2)){
        same = true;
        while(i<strLength(kata1) && same){
            if(kata1[i] != kata2[i]){
                same = false;
            }
            else{
                i++;
            }
        }
    }
    return same;
}

void clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// int main()
// {
//     STARTCMD();
//     printWord(GetCWord1());
//     printf("\n");
//     printWord(GetCWord2());
//     return 0;
// }