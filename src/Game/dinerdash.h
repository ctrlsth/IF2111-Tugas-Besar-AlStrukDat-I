#ifndef __DINERDASH__
#define __DINERDASH__

#include "../boolean.h"
#include "../ADT/array.h"
#include "../ADT/queue.h"

#define kapasitas 20
#define kapasitasQueue 50

typedef struct
{
    char *Makanan;
    int DurasiMasak;
    int Ketahanan;
    int Harga;
} Pesanan;

typedef struct
{
    Pesanan buffer[kapasitasQueue];
    int IdxHead;
    int IdxTail;
} QueuePesanan;

typedef struct
{
    Pesanan *buffer;
    int Capacity;
    int Neff;
} ArrayPesanan;

void CreateArrayPesanan(ArrayPesanan *array);

void DeallocateArrayPesanan(ArrayPesanan *array);

void InsertAPesananAt(ArrayPesanan *array, Pesanan el, int i);

void DeleteAPesananAt(ArrayPesanan *array, Pesanan *el, int i);

boolean isEmptyAPesanan(ArrayPesanan array);

int SearchArrayPesanan(ArrayPesanan array, Word food);

void CreateQueuePesanan(QueuePesanan *q);

boolean isEmptyQPesanan(QueuePesanan q);

void TabelPesanan(QueuePesanan qPesanan);

void TabelMasakan(ArrayPesanan qDiMasak);

void TabelSajian(ArrayPesanan qDiMasak);

Pesanan MakeRandomPesanan(int noAntrian);

void Inisialisasi(QueuePesanan *qPesanan);

void enqueuePesanan(QueuePesanan *q, Pesanan p);

void Memasak(ArrayPesanan *qDimasak, ArrayPesanan *qDiserve);

void Ketahanan(ArrayPesanan *qDiserve);

void dequeuePesanan(QueuePesanan *q, Pesanan *p);

int QueuePesananLength(QueuePesanan qpesanan);

int GetIdx(Word food, QueuePesanan qPesanan);

void Cook(QueuePesanan qPesanan, ArrayPesanan *qDiMasak, Word Food, boolean *turn_end);

void serve(ArrayPesanan *qDimasak, ArrayPesanan *qDiserve, QueuePesanan *qPesanan, Word food, int *saldo, boolean *endturn);

void dinerDASH();

#endif