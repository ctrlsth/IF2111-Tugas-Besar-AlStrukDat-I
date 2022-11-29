#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"
#include "mesinkata.h"
#include "array.h"

void showHistory(Stack played, int num)
{
    printf("Berikut adalah daftar game yang pernah dimainkan.\n");
    {
        int lens = played.TOP + 1;
        int i;
        if(num > lens)
        {
            num = lens;
        }
        printf("Berikut adalah daftar game yang telah dimainkan\n");
        for(i = num; i >= 0; i--)
        {
            printf("%c", ((played).T[i]));
        }
        printf("\n");
    }
}

void resetHistory(Stack played)
{
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY?\n");
    STARTCMD(false);
    if(compareWord(currentCommand, "YA"))
    {
        CreateEmpty(&played);
    }
    else
    {
        printf("History tidak jadi di-reset.\n");
        showHistory(played, played.TOP+1);
    }
}
