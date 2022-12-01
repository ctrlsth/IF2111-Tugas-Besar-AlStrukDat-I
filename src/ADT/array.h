#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include "mesinkata.h"
#include "../boolean.h"

// Boolean
#define boolean unsigned char
#define true 1
#define false 0
#define N_MAX 50

#define InitialSize 50
#define charsize 1

// typedef Games data;
typedef int IdxType;
typedef Word ElType;

typedef struct
{
    ElType *TW;
    int Capacity;
    int Neff;
} TabWord;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk TabWord kosong dengan ukuran InitialSize
 */
void MakeTabWord(TabWord *array);

/**
 * Destruktor
 * I.S. TabWord terdefinisi
 * F.S. array->TW terdealokasi
 */
void DeallocateTabWord(TabWord *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(TabWord array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(TabWord array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(TabWord array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(TabWord array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(TabWord *array, ElType el, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(TabWord *array, ElType el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(TabWord *array, ElType el);

/**
 * Fungsi untuk menghapus elemen di index ke-i TabWord
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(TabWord *array, IdxType i);

/**
 * Fungsi untuk menghapus elemen terakhir TabWord
 * Prekondisi: array tidak kosong
 */
void DeleteLast(TabWord *array);

/**
 * Fungsi untuk menghapus elemen pertama TabWord
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(TabWord *array);

/**
 * Fungsi untuk melakukan print suatu TabWord.
 * Prekondisi: array terdefinisi
 */
void PrintTabWord(TabWord array);

/**
 * Fungsi untuk melakukan copy suatu TabWord.
 * Prekondisi: array terdefinisi
 */
TabWord CopyTabWord(TabWord array);

/**
 * Fungsi untuk melakukan search suatu TabWord.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchTabWord(TabWord array, ElType el);

boolean isMemberArray(TabWord array, Word Kata);

#endif
