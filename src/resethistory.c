#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

void showHistory(Stack played, int num)
{
    printf("Berikut adalah daftar game yang pernah dimainkan.\n")
    {
        len = played.TOP + 1;
        stacktype game;
        int i;
        if(num > len)
        {
            num = len;
        }
        printf("Berikut adalah daftar game yang telah dimainkan\n");
        for(i = num; i >= 0; i--)
        {
            printf("%c", ((played).T[i]));
        }
        printf("\n");
    }
}

void ResetHistory(Stack played)
{
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY?\n");
    if(YA) //Ini input-an dari main, tolong bantu tanyain besok thanks
    {
        CreateEmpty(&played);
    }
    else
    {
        printf("History tidak jadi di-reset.\n");
        showHistory(played, played.TOP+1);
    }
}
