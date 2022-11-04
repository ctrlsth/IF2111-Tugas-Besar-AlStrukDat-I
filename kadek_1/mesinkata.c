#include <stdio.h>
#include <string.h>
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

/*###### Config Start ######*/
void C_STARTKATA(char *c)
{
    C_START(c);
    C_IgnoreBlank();
    if (CC == EOF) {
        EndKata = true;
    } else /* cc != MARK */ {
        EndKata = false;
        C_SalinKata();
    }
    C_IgnoreBlank();
    // C_START(c);
    // IgnoreBlank();
    // C_SalinKata();
}

void C_ADVKATA()
{
    C_IgnoreBlank();
    if (CC == EOF) {
        EndKata = true;
    } else /* cc != MARK */ {
        C_SalinKata();   
    }
    C_IgnoreBlank();
    // while ((CC == BLANK) || (CC == MARK))
    // {
    //     C_ADV();
    // }
    // C_SalinKata();
}
void C_SalinKata()
{
    int i = 0;
    while ((CC != MARK) && (CC != EOF))
    {
        CKata.TabKata[i] = CC;
        C_ADV();
        i++;
    }
    CKata.Length = i;
}
void C_IgnoreBlank()
{
    while ((CC == BLANK) || (CC == MARK))
    {
        C_ADV();
    }
}
/*###### Config End ######*/

void IgnoreBlank()
{
    while ((CC == BLANK) && (CC != MARK))
    {
        ADV();
    }
}

void SalinKata()
{
    int i = 0;
    while ((CC != MARK) && (CC != BLANK))
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i;
}

void STARTKATA()
{
    START();
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
{
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        SalinKata();
    }
}
Kata AskCommand()
{
    STARTKATA();
    while (!EndKata)
    {
        ADVKATA();
    }
    return CKata;
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

boolean STRCOMP(Kata k1, char* k2)
{
    int i = 0;
    int lengthk2 = strLength(k2);
    boolean sama = false;
    if(k1.Length == lengthk2){
        sama = true;
    // (k1.Length == lengthk2) &&
        while ((sama) && (i < lengthk2))
        {
            // printf("MASUK KE CEK KATA\n");
            // printf("K1 CKata = %c\n", k1.TabKata[i]);
            // printf("K2 CKata = %c\n", k2[i - 1]);
            if (k1.TabKata[i] != k2[i])
            {
                sama = false;
            }
            i++;
        }
    }
        return sama;
}

boolean IsNumber(Kata k)
{
    int i;
    if (CKata.TabKata[0] == '-')
    {
        i = 1;
    }
    else
    {
        i = 0;
    }
    boolean number = true;
    while (number && i <= k.Length)
    {
        switch (k.TabKata[i])
        {
        case '0':
            break;
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        default:
            number = false;
        };
        i++;
    }
    return number;
}
int KataInt(Kata k)
{
    int i;
    char huruf;
    int value = 0;
    for (i=0;i<k.Length;i++){
        huruf = k.TabKata[i];
        value = (value*10) + (huruf - '0');
    }
    return value;
}
// void KataMap(Kata k, char importMap[100])
// {
//     for (int i = 1; i <= k.Length; i++)
//     {
//         importMap[i - 1] = k.TabKata[i];
//     }
// }
// void KataPlayer(Kata k, char namaPlayer[20])
// {
//     for (int i = 1; i <= k.Length; i++)
//     {
//         namaPlayer[i - 1] = k.TabKata[i];
//     }
// }
void printKata(Kata kata)
{
    for (int i = 1; i <= kata.Length; i++)
    {
        printf("%c", kata.TabKata[i]);
    }
    puts("");
}

char* toString(Kata kata){
    char* str;
    int i;
    // char temp[kata.Length + 1];
    for(i=0;i<kata.Length;i++){
        str[i] = kata.TabKata[i];
    }
    str[i] = '\0';
    // printf("%s\n",temp);
    // str = temp;
    // str[kata.Length + 1] = '\0';
    // for(i=0;i<kata.Length;i++){
    //     printf("%c",str[i]);
    // }
    return str;
}