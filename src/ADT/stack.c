// NIM              : 18221171
// Nama             : Hans Stephano E
// Tanggal          : 21 Oktober 2022
// Topik praktikum  : Pra-Praktikum 7 - #1
// Deskripsi        : Implementasi "stack.h"

/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include <stdio.h>
#include "stack.h"
#include "../boolean.h"

// #define StackNil -1
// #define MaxEl 100
// /* StackNil adalah stack dengan elemen kosong . */

// typedef int infostack;
// typedef int address;   /* indeks tabel */

// /* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
// /* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
// typedef struct { 
//   infostack T[MaxEl]; /* tabel penyimpan elemen */
//   address TOP;  /* alamat TOP: elemen puncak */
// } Stack;
// /* Definisi stack S kosong : S.TOP = StackNil */
// /* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
// /* Jika S adalah Stack maka akses elemen : */
//    /* S.T[(S.TOP)] untuk mengakses elemen TOP */
//    /* S.TOP adalah alamat elemen TOP */

// /* Definisi akses dengan Selektor : Set dan Get */
// #define Top(S) (S).TOP
// #define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai StackNil */
{
    Top(*S) = StackNil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == StackNil);
}
boolean IsStackFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == (MaxEl-1));
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infostack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsStackEmpty(*S))
    {
        Top(*S) = 0;
        InfoTop(*S) = X;
    }
    else
    {
        if (!IsStackFull(*S))
        {
            Top(*S) += 1;
            InfoTop(*S) = X;
        }
    }

    // Top(*S) += 1;
    // InfoTop(*S) = X;

}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infostack* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X) = InfoTop(*S);
    Top(*S) -= 1;

    /*
    if (Top(*S) < 0)
    {
        Top(*S) = StackNil;
    }
    */
}