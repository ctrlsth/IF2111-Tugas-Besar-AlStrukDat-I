#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "boolean.h"

const int IDX_UNDEF = -1;
const int CAPACITY = 15;

typedef struct {
    char Makanan[3];
    int DurasiMasak;
    int Ketahanan;
    int Harga;
} Pesanan;

typedef struct {
    Pesanan buffer[15];
    int IdxHead;
    int IdxTail;
    int Count;
} Queue;

void CreateQueue (Queue *q);

boolean IsEmpty(Queue q);

void TabelPesanan(Queue qPesanan);

void TabelMasakan(Queue qDiMasak);

void TabelSajian(Queue qDiMasak);

Pesanan MakeRandomPesanan(int noAntrian);

int AcakHarga();

int AcakDurasi();

void Inisialisasi(Queue *qPesanan);

void enqueue(Queue *q, Pesanan p);


void dequeue(Queue *q, Pesanan *p);

void eliminate(Queue *q, char FoodId[]);

int GetIdx(Queue q, char FoodId[]);

boolean IsDuaDigit(char str[]);

int GetId(char str[]);

boolean IsFinish(Queue qPesanan, Queue qSelesai);

void Berkurang(Queue *qDiMasak);

void Cook(Queue qPesanan, Queue *qDiMasak, char FoodId[]);

void Serve(Queue *qPesanan, Queue *qDiMasak, Queue *qSelesai, char FoodId[]);

boolean IsCook(char command[]);

boolean IsServe(char command[]);

boolean IsSkip(char command[]);

boolean IsCommandValid(char command[], char FoodId[], Queue qPesanan, Queue qDiMasak);

void Komando(char command[], char FoodId[], Queue *qPesanan, Queue *qDiMasak, Queue *qSelesai);

int main ();
    
