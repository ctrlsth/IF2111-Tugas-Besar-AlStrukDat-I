#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "queue.h"

void displayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("[]\n");
    }
    else
    {
        int i;
        printf("[");
        for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i + 1) % CAPACITY)
        {
            printf("%d,", q.buffer[i]);
        }
        printf("%d]\n", TAIL(q));
    }
}

/*
    Terima input dari START dan LOAD
*/
int main()
{
    Queue gamequeue;
    displayQueue(gamequeue);
}

