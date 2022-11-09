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
        printf("Queue is full!\n");
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
        printf("\n");
    }
    else
    {
        int i,j;
        int count = 1;
        for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i + 1) % CAPACITY)
        {
            printf("%d. ",count);
            for(j=0;j<q.buffer[i].Length;j++)
            {
                printf("%c", q.buffer[i].TabKata[j]);
            }
            printf("\n");
            count +=1;
        }
        printf("%d. ", count);
        for(j=0;j<q.buffer[i].Length;j++)
            {
                printf("%c", q.buffer[i].TabKata[j]);
            }
            printf("\n\n");
        // printf("%d]\n", TAIL(q));
    }
}

boolean isMemberQueue(Kata word, Queue queue){
    int i = queue.idxHead;
    int j;
    boolean sama = false;
    if (!isEmpty(queue)){
        while (i != queue.idxTail && !sama){
            if(word.Length == queue.buffer[i].Length){
                sama = true;
                for(j=0;j<word.Length;j++){
                    if (word.TabKata[j] != queue.buffer[i].TabKata[j]){
                        sama = false; //jika benar semua maka sama = true (tidak berubah)
                    }
                }
            }
            i = (i+1) % CAPACITY;
        }
    
        // i == queue.IdxTail
        if(!sama){
            if(word.Length == queue.buffer[i].Length){
                sama = true;
                for(j=0;j<word.Length;j++){
                    if (word.TabKata[j] != queue.buffer[i].TabKata[j]){
                        sama = false; //jika benar semua maka sama = true (tidak berubah)
                    }
                }
            }
        }
    }
    return sama;
}