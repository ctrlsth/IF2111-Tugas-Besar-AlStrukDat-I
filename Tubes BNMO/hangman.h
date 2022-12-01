#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "ADT MESIN KATA/mesin_kata.h"

#define IDX_UNDEF -1
#define MARKK '_'
#define KESEMPATAN 10

typedef struct {
    char kata[KESEMPATAN];
    int panjang;
} List;

void CreateList(List *LSoal, int digit);
//untuk membuat sebuah list kosong dengan tampilan Mark sebanyak digit.

void CreateEmpty(List*Lsalah);
//prosedur untuk membuat sebuah list kosong dengan panjang IDX_UNDEF

int printSoal(int urutan);
//fungsi untuk menampilkan soal pertanyaan

void variasiSoal(int urutan, List *L);
//prosedur untuk mencetak jawaban

void TampilanGaris(List Lsalah);
//prosedur untuk menampilkan visualisasi hangman, berdasarkan jumlah salah

void DeleteAt(List *Lbenar, List LSoal, int indeks);
//prosedur untuk menghapus elemen ke-indeks

void InsertAt(List *Lbenar, List LSoal, int indeks);
//prosedur untuk memasukkan elemen (pada indeks yang telah ditentukan) ke dalam list

void DigitBenar(List *LSoal, char huruf, List *Lsalah, List *Lbenar);
//prosedur untuk merubah tampilan dari '_' menjadi huruf yg ditebak (jika tebakan benar).
//prosedur ini juga akan memasukkan huruf yang tebakannya salah ke dalam list huruf yg salah.

void PrintList(List L, int max);
//prosedur untuk menampilkan isi daripada List

void TampilanGame(List Lbenar, List Lsalah, int urutan, List LSoal);
//prosedur untuk menampilkan tampilan game

boolean isExist(char huruf, List Lsalah, List Lbenar, List LSoal);
//fungsi untuk mencari huruf di dalam list. Fungsi akan mengembalikan true bila huruf dapat ditemukan.

boolean IsFinished(List Lsalah, List Lbenar, List LSoal);
//fungsi untuk mengecek apakah game sudah selesai atau belum

void HangMan(int skorhangman);
//prosedur utama dari game hangman