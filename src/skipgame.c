#include "queue.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void SkipGame(Queue queuegame, int num)
{
    displayQueue(queuegame);
    int i;
    ElType game;
    for(i = 0; i <= num; i++)
    {
        dequeue(&queuegame, &game);
    }
    printf("Loading ");
    printWord(game);
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