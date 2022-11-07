#include "queue.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void displayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("Kosong.\n");
    }
    else
    {
        int i;
        for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i + 1) % CAPACITY)
        {
            printf("%d. %d\n", (i+1), q.buffer[i]);
        }
        printf("%d\n", TAIL(q));
    }
}

void TulisIsi(TabWord T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
    if (IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
        {
            printf("%d:%d\n", i, GetElmt(T, i));
        }
    }
}

void QueueGame(Queue queuegame, TabWord listgame)
{
    printf("Berikut adalah daftar antrian game-mu :\n");
    displayQueue(queuegame);
    printf("Berikut adalah daftar game yang tersedia :\n");
    TulisIsi(listgame);
}

int main()
{
    Queue q1;
    CreateQueue(&q1);
/*     enqueuez(&q1,"satu");
    enqueuez(&q1,"dua");
    enqueuez(&q1,"tiga");
 */    displayQueue(q1);
}