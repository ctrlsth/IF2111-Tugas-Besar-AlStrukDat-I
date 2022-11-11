#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../boolean.h"
#include "dinerdash.h"

void CreateQueuePesanan(QueuePesanan *q)
{
    q->IdxHead = IDX_UNDEF;
    q->IdxTail = IDX_UNDEF;
}

void CreateArrayPesanan(ArrayPesanan *array)
{
    array->buffer = (Pesanan *)malloc(kapasitas * (sizeof(Pesanan)));
    array->Capacity = kapasitas;
    array->Neff = 0;
}

boolean isEmptyAPesanan(ArrayPesanan array)
{
    return array.Neff == 0;
}

void DeallocateArrayPesanan(ArrayPesanan *array)
{
    free(array->buffer);
    array->Neff = 0;
    array->Capacity = 0;
}

void InsertAPesananAt(ArrayPesanan *array, Pesanan el, int i)
{
    if (array->Neff == array->Capacity)
    {
        int desiredCapacity = array->Capacity + kapasitas;
        Pesanan *arr = (Pesanan *)malloc(desiredCapacity * (sizeof(Pesanan)));
        for (int j = 0; j < array->Neff; j++)
        {
            arr[j] = array->buffer[j];
        }
        free(array->buffer);
        array->buffer = arr;
        array->Capacity = desiredCapacity;
    }
    for (int j = array->Neff - 1; j >= i; j--)
    {
        (*array).buffer[j + 1] = (*array).buffer[j];
    }
    array->buffer[i] = el;
    array->Neff += 1;
}

void DeleteAPesananAt(ArrayPesanan *array, Pesanan *el, int i)
{
    for (int j = i; j < array->Neff - 1; j++)
    {
        array->buffer[j] = array->buffer[j + 1];
    }
    array->Neff -= 1;
}

boolean isEmptyQPesanan(QueuePesanan q)
{
    return (q).IdxHead == IDX_UNDEF && (q).IdxTail == IDX_UNDEF;
}

void TabelPesanan(QueuePesanan qPesanan)
{
    int i;
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("---------------------------------------------\n");
    if (isEmptyQPesanan(qPesanan))
    {
        printf("        |                |           |\n");
    }
    else
    {
        for (i = qPesanan.IdxHead; i != qPesanan.IdxTail; i = (i + 1) % kapasitasQueue)
        {
            printf("%s      | %d             | %d        | %d\n", (qPesanan).buffer[i].Makanan, (qPesanan).buffer[i].DurasiMasak, (qPesanan).buffer[i].Ketahanan, (qPesanan).buffer[i].Harga);
        }
        printf("%s      | %d             | %d        | %d\n", (qPesanan).buffer[i].Makanan, (qPesanan).buffer[i].DurasiMasak, (qPesanan).buffer[i].Ketahanan, (qPesanan).buffer[i].Harga);
    }
}

void TabelMasakan(ArrayPesanan qDiMasak)
{
    int i;
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("-----------------------------\n");
    if (isEmptyAPesanan(qDiMasak))
    {
        printf("        |\n");
    }
    else
    {
        for (i = 0; i < qDiMasak.Neff; i++)
        {
            printf(" %s      | %d\n", (qDiMasak).buffer[i].Makanan, (qDiMasak).buffer[i].DurasiMasak);
        }
    }
}

void TabelSajian(ArrayPesanan qDiServe)
{
    int i;
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("-----------------------------\n");
    if (isEmptyAPesanan(qDiServe))
    {
        printf("        |\n");
    }
    else
    {
        for (i = 0; i < qDiServe.Neff; i++)
        {
            printf(" %s      | %d\n", (qDiServe).buffer[i].Makanan, (qDiServe).buffer[i].Ketahanan);
        }
    }
}

Pesanan RandomPesanan(int noAntrian)
{
    Pesanan p;
    int durasi = (rand() % 5) + 1;
    int ketahanan = (rand() % 5) + 1;
    int harga = (rand() % 40001) + 10000;
    int antrian = noAntrian - 1;
    int count = 0;
    char kode = 'M';
    char *kodemakanan;
    if (antrian < 10)
    {
        kodemakanan = (char *)malloc(3 * sizeof(char));
        char k1 = (antrian) + '0'; // biar jadi string, pake trik ASCII
        kodemakanan[0] = kode;
        kodemakanan[1] = k1;
        kodemakanan[2] = '\0';
    }
    else
    { // antrian >= 10
        while (antrian >= 10)
        {
            antrian -= 10;
            count += 1;
        }
        kodemakanan = (char *)malloc(4 * sizeof(char));
        char k1 = count + '0';
        char k2 = antrian + '0';
        kodemakanan[0] = kode;
        kodemakanan[1] = k1;
        kodemakanan[2] = k2;
        kodemakanan[3] = '\0';
    }
    p.Makanan = kodemakanan;
    p.DurasiMasak = durasi;
    p.Ketahanan = ketahanan;
    p.Harga = harga;
    // free(&kodemakanan);
    return (p);
}

// int AcakHarga(){
//     return ((rand()%40001) + 10000);
// }

// int AcakDurasi(){
//     return ((rand()%5)+1);
// }

void Inisialisasi(QueuePesanan *qPesanan)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        Pesanan p = RandomPesanan(i + 1);
        enqueuePesanan(qPesanan, p);
    }
}

void enqueuePesanan(QueuePesanan *q, Pesanan p)
{
    if (isEmptyQPesanan(*q))
    {
        (*q).IdxHead = 0;
    }
    (*q).IdxTail = (q->IdxTail + 1) % kapasitasQueue;
    (*q).buffer[q->IdxTail] = p;
}

void dequeuePesanan(QueuePesanan *q, Pesanan *p)
{
    *p = (*q).buffer[(*q).IdxHead];
    if ((*q).IdxHead == (*q).IdxTail)
    {
        (*q).IdxHead = IDX_UNDEF;
        (*q).IdxTail = IDX_UNDEF;
    }
    else
    {
        (*q).IdxHead = ((*q).IdxHead + 1) % kapasitasQueue;
    }
}

int GetIdx(Word food, QueuePesanan qPesanan)
{
    int i = qPesanan.IdxHead;
    boolean found = false;
    while (i != qPesanan.IdxTail && !found)
    {
        if (compareWord(food, qPesanan.buffer[i].Makanan))
        {
            found = true;
        }
        else
        {
            i = (i + 1) % kapasitasQueue;
        }
    }
    // found || i == qPesanan.IdxTail
    if (!found)
    {
        if (compareWord(food, qPesanan.buffer[i].Makanan))
        {
            return i;
        }
        else
        {
            return IDX_UNDEF;
        }
    }
    else
    {
        return i;
    }
}

void Cook(QueuePesanan qPesanan, ArrayPesanan *qDiMasak, Word food, boolean *turn_end)
{
    int index = GetIdx(food, qPesanan);
    char *makanan = toString(food);
    if (qDiMasak->Neff < 5)
    {
        if (index != IDX_UNDEF)
        {
            InsertAPesananAt(qDiMasak, qPesanan.buffer[index], qDiMasak->Neff);
            qDiMasak->buffer[qDiMasak->Neff - 1].DurasiMasak += 1;
            printf("Berhasil memasak %s\n", makanan);
            *turn_end = true;
        }
        else
        {
            printf("%s tidak ada dalam pesanan\n", makanan);
        }
    }
    else
    {
        printf("Memasak > 5 makanan dalam satu waktu merupakan sebuah tindakan yang dilarang\n");
    }
}

void serve(ArrayPesanan *qDimasak, ArrayPesanan *qDiserve, QueuePesanan *qPesanan, Word food, int *saldo, boolean *endturn)
{
    Pesanan order;
    int indexMasak = SearchArrayPesanan(*qDimasak, food);
    int indexServe = SearchArrayPesanan(*qDiserve, food);
    int indexPesanan = GetIdx(food, *qPesanan);
    char *makanan = toString(food);
    if (indexServe != IDX_UNDEF)
    {
        if (indexPesanan != qPesanan->IdxHead)
        {
            printf("%s belum dapat disajikan karena %s belum selesai\n", makanan, qPesanan->buffer[qPesanan->IdxHead].Makanan);
        }
        else
        {
            printf("Berhasil mengantar %s\n", makanan);
            (*endturn) = true;
            (*saldo) += qPesanan->buffer[indexPesanan].Harga;
            DeleteAPesananAt(qDiserve, &order, indexServe);
            dequeuePesanan(qPesanan, &order);
        }
    }
    else
    {
        if (indexMasak != IDX_UNDEF)
        {
            printf("%s belum selesai dimasak\n", makanan);
        }
        else
        {
            if (indexPesanan != IDX_UNDEF)
            {
                printf("%s belum dimasak\n", makanan);
            }
            else
            {
                printf("%s tidak terdapat dalam antrian\n", makanan);
            }
        }
    }
}

int SearchArrayPesanan(ArrayPesanan array, Word food)
{
    int i = 0;
    boolean found = false;
    while (i < array.Neff && !found)
    {
        if (compareWord(food, array.buffer[i].Makanan))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    if (!found)
    {
        return IDX_UNDEF;
    }
    else
    {
        return i;
    }
}

int QueuePesananLength(QueuePesanan qpesanan)
{
    int i = qpesanan.IdxHead;
    int count = 0;
    while (i != qpesanan.IdxTail)
    {
        count += 1;
        i = (i + 1) % kapasitasQueue;
    }
    return (count + 1);
}

void Memasak(ArrayPesanan *qDimasak, ArrayPesanan *qDiserve)
{
    int i;
    int j = 0;
    Pesanan order;
    if (!isEmptyAPesanan(*qDimasak))
    {
        for (i = 0; i < qDimasak->Neff; i++)
        {
            qDimasak->buffer[i].DurasiMasak -= 1;
        }
        while (j != qDimasak->Neff)
        {
            if (qDimasak->buffer[j].DurasiMasak == 0)
            {
                printf("Makanan %s telah selesai dimasak\n", qDimasak->buffer[j].Makanan);
                InsertAPesananAt(qDiserve, qDimasak->buffer[j], qDiserve->Neff);
                DeleteAPesananAt(qDimasak, &order, j);
            }
            else
            {
                j += 1;
            }
        }
    }
}

void Ketahanan(ArrayPesanan *qDiserve)
{
    int i;
    int j = 0;
    Pesanan order;
    if (!isEmptyAPesanan(*qDiserve))
    {
        for (i = 0; i < qDiserve->Neff; i++)
        {
            qDiserve->buffer[i].Ketahanan -= 1;
        }
        while (j != qDiserve->Neff)
        {
            if (qDiserve->buffer[j].Ketahanan == 0)
            {
                printf("Makanan %s telah busuk\n", qDiserve->buffer[j].Makanan);
                DeleteAPesananAt(qDiserve, &order, j);
            }
            else
            {
                j++;
            }
        }
    }
}

void dinerDASH()
{
    time_t waktu;
    srand(time(&waktu));
    printf("\nSelamat Datang di Diner Dash!\n");
    QueuePesanan qPesanan;
    ArrayPesanan qDiMasak;
    ArrayPesanan qSelesai;
    TabWord Command;
    CreateQueuePesanan(&qPesanan);
    CreateArrayPesanan(&qDiMasak);
    CreateArrayPesanan(&qSelesai);
    int saldo = 0;
    int antrian = 3;
    int count = 0;
    Inisialisasi(&qPesanan);
    boolean ended = false;
    boolean turn_end = false;
    while (!ended)
    {
        MakeTabWord(&Command);
        printf("SALDO : %d", saldo);
        printf("\n\n");
        // printf("COUNT: %d\n\n",count);
        TabelPesanan(qPesanan);
        printf("\n");
        TabelMasakan(qDiMasak);
        printf("\n");
        TabelSajian(qSelesai);
        printf("\n\n");
        printf("MASUKKAN COMMAND: ");
        STARTCMD(false);
        system("cls");
        while (!EndWord)
        {
            InsertLast(&Command, currentCommand);
            ADVCMD(false);
        }
        if (Command.Neff == 2)
        {
            if (compareWord(Command.TW[0], "COOK"))
            {
                Cook(qPesanan, &qDiMasak, Command.TW[1], &turn_end);
            }
            else if (compareWord(Command.TW[0], "SERVE"))
            {
                serve(&qDiMasak, &qSelesai, &qPesanan, Command.TW[1], &saldo, &turn_end);
                if (turn_end)
                {
                    count += 1;
                }
            }
            else
            {
                printf("Command tidak valid\n");
            }
        }
        else if (Command.Neff == 1)
        {
            if (compareWord(Command.TW[0], "SKIP"))
            {
                turn_end = true;
            }
            else
            {
                printf("Command tidak valid\n");
            }
        }
        else
        {
            printf("Command tidak valid\n");
        }
        if (turn_end)
        {
            Ketahanan(&qSelesai);
            Memasak(&qDiMasak, &qSelesai);
            antrian += 1;
            Pesanan p = RandomPesanan(antrian);
            enqueuePesanan(&qPesanan, p);
            printf("============================================\n");
            if (count == 15 || QueuePesananLength(qPesanan) > 7)
            {
                printf("Permainan Selesai\n");
                printf("Skor Akhir : %d\n", saldo);
                ended = true;
            }
            turn_end = false;
        }
        DeallocateTabWord(&Command);
    }
}