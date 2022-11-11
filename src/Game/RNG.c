#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../boolean.h"
#include "../ADT/mesinkata.h"

int acakAngka()
{
    // time_t waktu;
    int BilRandom;
    srand(time(0));

    BilRandom = rand() % 101;//buat bilangan random dengan maksimal angka yang keluar adalah 100
    return (BilRandom);
}

void RNG()
{
    int tebakan;
    int jawaban;
    int skor = 100; //skor max 100 dan skor akan berkurang (-5) setiap user melakukan satu kesalahan
    boolean found = false;
    
    jawaban = acakAngka();
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    while(!found && skor >0)
    {
        STARTCMD(false);
        system("cls");
        if(isNumber(currentCommand))
        {
            tebakan = toInt(currentCommand);
            printf("%d\n",tebakan);
            if (tebakan == jawaban)
            {
                printf("Ya, X adalah %d\n", jawaban);
                printf("Skor akhir Anda: %d\n",skor);
                found = true;
            } 
            else
            {
                if(tebakan > jawaban)
                {
                    printf("Lebih kecil\n");
                    skor -=5;
                }

                else if (tebakan < jawaban)
                {
                    printf("Lebih besar\n");
                    skor -=5;
                }
            }
        }

        else{
            printf("input tidak valid\n");
        }
    }
    if (skor == 0)
    {
        printf("Sayang sekali Anda belum bisa menjawab dengan tepat\n");
        printf("X adalah %d\n",jawaban);
        printf("Skor akhir Anda = %d\n",skor);
    }
}