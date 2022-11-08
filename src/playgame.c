#include "queue.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void PlayGame(Queue queuegame)
{
    printf("Berikut adalah daftar antrian game-mu :\n");
    //displayQueueGame();
    ElType game;
    dequeue(&queuegame, &game);
    printf("Loading ");
    printWord(game);
    print("..\n");
    //Panggil fungsi dari game itu
}
