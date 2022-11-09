#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

/*###### Config Start ######*/
void C_STARTKATA(char *c,boolean * fileopen) //membaca file
{
    C_START(c,fileopen);
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

void SalinKataGame(){
    int i = 0;
    while ((CC != MARK))
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i;
}

void STARTKATAGAME(){ //Memasukkan nama game
    START();
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKataGame();
    }
}
void STARTKATA() // memasukkan command
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
    int i = 0;
    boolean number = false;
    if(k.Length > 0){
        number = true; 
        while(i<k.Length && number){
            if (!(k.TabKata[i] > '0' && k.TabKata[i] < '9')){
                number = false;
            }
            i++;
        }
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

void printKata(Kata kata)
{
    for (int i = 0; i < kata.Length; i++)
    {
        printf("%c", kata.TabKata[i]);
    }
}

char* toString(Kata kata){
    char* str;
    int i;
    str = (char*) malloc((kata.Length + 1)*sizeof(char*));
    for(i=0;i<kata.Length;i++){
        str[i] = kata.TabKata[i];
    }
    str[i] = '\0';
    return str;
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
