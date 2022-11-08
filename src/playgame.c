#include "queue.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void PlayGame(Queue queuegame)
{
    displayQueue(queuegame);
    ElType *game;
    dequeue(&queuegame, game);
    printf("Loading ");
    printWord(*game);
    print("..\n");
    // if(game == "RNG")
    // {

    // }
    // else if(game == "Diner Dash" )
    // {

    // }
    // else if(game == "")
    // {

    // }
    // else
    // {
    //     printf("Total score = ");
    // }
}