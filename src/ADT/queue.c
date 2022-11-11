
#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q)
{
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFull(Queue q)
{
    return IDX_HEAD(q) == (IDX_TAIL(q) + 1) % CAPACITY;
}

int length(Queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY) % CAPACITY + 1;
    }
}

void enqueue(Queue *q, ElType val)
{
    if (isFull(*q))
    {
        printf("Antrian sudah penuh!\n");
    }
    else
    {
        if (isEmpty(*q))
        {
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val)
{
    if (isEmpty(*q))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        *val = HEAD(*q);
        if (IDX_HEAD(*q) == IDX_TAIL(*q))
        {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        }
        else
        {
            IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
        }
    }
}

void displayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("Antrian game Anda kosong.\n");
    }
    else
    {
        printf("Berikut adalah antrian game Anda :\n");
        int i, j = 1;
        for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i = (i + 1) % CAPACITY)
        {
            printf("%d. ", j);
            Word game_name = q.buffer[i];
            printWord(game_name);
            printf("\n");
            j++;
        }
        printf("\n");
    }
}

boolean isInQueue(Queue queueGame, Word gameName)
{
    int i = 0;
    boolean notFound = true;
    while (i < length(queueGame) && notFound)
    {
        if (compare2Word(queueGame.buffer[i], gameName))
        {
            notFound = false;
        }
        i++;
    }
    return !notFound;
}