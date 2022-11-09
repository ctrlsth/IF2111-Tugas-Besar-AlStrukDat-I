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
    boolean game1 = compareWord(*game, "RNG");
    boolean game2 = compareWord(*game, "Diner DASH");
    boolean game3 = compareWord(*game, "DINOSAUR IN EARTH");
    boolean game4 = compareWord(*game, "RISEWOMAN");
    boolean game5 = compareWord(*game, "EIFFEL TOWER");
    if(game1)
    {

    }
    else if(game2)
    {

    }
    else if(game3)
    {

    }
    else if(game4)
    {

    }
    else if(game5)
    {

    }
    else
    {
        printf("Total score = 10\n");
    }
}