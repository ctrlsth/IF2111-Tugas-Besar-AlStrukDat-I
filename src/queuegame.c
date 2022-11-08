#include "queue.h"
#include "array.h"
#include "mesinkata.h"
//#include "listgame.h"
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void ForQueueGame(Queue queuegame, TabWord listgame)
{
    displayQueue(queuegame);
    printf("Berikut adalah daftar game yang tersedia :\n");
    TulisIsi(listgame);
    printf("Nomor game yang mau ditambahkan ke antrian : ");
    STARTWORD();
    int i = CC - '0';
    enqueue(&queuegame,listgame.TI[i-1]);
    printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
}