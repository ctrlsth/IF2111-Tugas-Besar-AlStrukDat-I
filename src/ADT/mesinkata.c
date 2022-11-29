#include "mesinkata.h"
#include <stdlib.h>
#include <stdio.h>

/* State Mesin Kata */
boolean EndWord;
Word currentWord;
Word currentCommand;

// ** Mengakuisisi kata dari file.txt ** //
void STARTWORD(char *txtfile, boolean *openSuccess)
{
    loadstart(txtfile, openSuccess);
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
}

void ADVWORD()
{
    IgnoreBlanks();
    if (CC == EOF)
    {
        EndWord = true;
    }
    else
    {
        COPYWORD();
        IgnoreBlanks();
    }
}

void COPYWORD()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((CC != EOF) && (CC != MARK) && (i < NMax))
    {
        currentWord.TabChar[i] = CC;
        adv(true);
        i++;
    }
    currentWord.Length = i;
}

void IgnoreBlanks()
{
    while (CC == BLANK || CC == MARK)
    {
        adv(true);
    }
}

// ** Mengakuisisi COMMAND dari MAIN.C ** //
void STARTCMD(boolean inputGame)
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, currentCommand adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    cmdstart();
    IgnoreBlanksCMD();
    if (CC == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVCMD(inputGame);
    }
}

void ADVCMD(boolean inputGame)
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentCommand adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure COPYCMD */
{
    if (CC == MARK)
    {
        EndWord = true;
    }
    else
    {
        (inputGame) ? COPYGAME() : COPYCMD();
        IgnoreBlanksCMD();
    }
}

void COPYCMD()
/* Mengakuisisi command, menyimpan dalam currentCommand
   I.S. : CC adalah karakter pertama dari kata
   F.S. : currentCommand berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((CC != BLANK) && (CC != MARK) && (i < NMax))
    {
        currentCommand.TabChar[i] = CC;
        adv(false);
        i++;
    }
    currentCommand.Length = i;
}

void COPYGAME()
/* Mengakuisisi nama game, menyimpan dalam currentCommand
   I.S. : CC adalah karakter pertama dari kata
   F.S. : currentCommand berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((CC != MARK) && (i < NMax))
    {
        currentCommand.TabChar[i] = CC;
        adv(false);
        i++;
    }
    currentCommand.Length = i;
}

void IgnoreBlanksCMD()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK atau CC = EOF */
{
    while (CC == BLANK)
    {
        adv(false);
    }
}

// Fungsi Umum //

Word toWord(char *someString)
/* Mengubah type String menjadi type Kata
   I.S. : string masukan bisa kosong */
{
    Word converted;
    int i = 0;
    while (someString[i] != '\0' && someString[i] != ' ')
    {
        converted.TabChar[i] = someString[i];
    }
    converted.Length = i;

    return converted;
}

char *toString(Word kata)
{
    char *str = (char *)malloc((kata.Length) * sizeof(char));
    int i;

    for (i = 0; i < kata.Length; i++)
    {
        str[i] = kata.TabChar[i];
    }
    str[i] = '\0';

    return str;
}

int toInt(Word kata)
{
    int i, X = 0;
    for (i = 0; i < kata.Length; i++)
    {
        // printf("Huruf ke-%d = %c", i, kata.TabChar[i]);
        X = X * 10 + (kata.TabChar[i] - '0');
        // printf("X ke-%d = %d\n", i, X);
    }
    return X;
}

boolean isNumber(Word kata)
{
    int i = 0;
    boolean number = true;
    while (i < kata.Length && number)
    {
        if (kata.TabChar[i] < '0' || kata.TabChar[i] > '9')
        {
            number = false;
        }
        i++;
    }
    
    return number;
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
            if (kata1.TabChar[i] != kata2[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
    return false;
}

boolean compare2Word(Word kata1, Word kata2)
/* Membandingkan 2 buah word
   True     : Jika kedua word sama,
   False    : Jika berbeda */
{
    if (kata1.Length == kata2.Length)
    {
        int i = 0;
        while (i < kata1.Length)
        {
            if (kata1.TabChar[i] != kata2.TabChar[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
    return false;
}

int strLength(char *strings)
/* Mengembalikan panjang suatu string */
{
    int i = 0;
    while (strings[i] != '\0')
    {
        i++;
    }
    return i;
}

void printWord(Word Kata)
/* Menampilkan masukan Kata pada layar */
{
    int i;
    for (i = 0; i < Kata.Length; i++)
    {
        printf("%c", Kata.TabChar[i]);
    }
    // printf("\n");
}

void binSep(Word Kata, Word *Kata1, Word *Kata2, char separator)
{
    int i, j = 0;
    boolean passedSep;
    for (i = 0; i < Kata.Length; i++)
    {
        if (passedSep)
        {
            Kata2->TabChar[j] = Kata.TabChar[i];
            j++;
        }
        else
        {
            if (Kata.TabChar[i] == separator)
            {
                passedSep = true;
                Kata1->Length = i;
            }
            else
            {
                Kata1->TabChar[i] = Kata.TabChar[i];
            }
        }
    }

    Kata2->Length = j;
}

void UPPER(Word *Kata)
{
    int i;
    for (i = 0; i < Kata->Length; i++)
    {
        if (Kata->TabChar[i] >= 97 && Kata->TabChar[i] <= 122)
        {
            Kata->TabChar[i] -= 32;
        }
    }
}
// int main()
// {
//     boolean apa;
//     STARTWORD("src/ADT/config.txt", &apa);
//     printf("apa: %d\n", apa);
//     printWord(currentWord);
//     printf("Passed\n");
//     int n = toInt(currentWord);
//     printf("n = %d\n", n);

//     ADVWORD();
//     printWord(currentWord);
//     ADVWORD();
//     printWord(currentWord);
//     return 0;
// }