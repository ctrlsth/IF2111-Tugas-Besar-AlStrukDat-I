#include "queue.h"
#include "array.h"
//#include "listgame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void displayQueueGame(Queue q)
{
    if (isEmpty(q))
    {
        printf("Anda sedang tidak memiliki antrian game\n");
    }
    else
    {
        int i;
        for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i + 1) % CAPACITY)
        {
            Word thegame = q.buffer[i];
            printf("%d. %d\n", (i+1), q.buffer[i]);
        }
        printf("%d\n", TAIL(q));
    }
}

void ForQueueGame(Queue queuegame, TabWord listgame)
{
    printf("Berikut adalah daftar antrian game-mu :\n");
    displayQueueGame(queuegame);
    printf("Berikut adalah daftar game yang tersedia :\n");
    //list the game; *import dari Felisa*
    printf("Nomor game yang mau ditambahkan ke antrian :\n");
    STARTWORD();
    enqueue(&queuegame, (n-1)); //Apabila n adalah input-an 
}