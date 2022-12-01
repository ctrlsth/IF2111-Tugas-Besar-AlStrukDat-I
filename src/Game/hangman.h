#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../boolean.h"
#include "../ADT/mesinkata.h"

#define IDX_UNDEF -1
#define MARKK '_'
#define KESEMPATAN 10

typedef struct {
    char kata[KESEMPATAN];
    int panjang;
} ListH;

void CreateListH(ListH *LSoal, int digit);
//untuk membuat sebuah list kosong dengan tampilan Mark sebanyak digit.

void CreateEmptyH(ListH*Lsalah);
//prosedur untuk membuat sebuah list kosong dengan panjang IDX_UNDEF

int printSoal(int urutan);
//fungsi untuk menampilkan soal pertanyaan

void variasiSoal(int urutan, ListH *L);
//prosedur untuk mencetak jawaban

void TampilanGaris(ListH Lsalah);
//prosedur untuk menampilkan visualisasi hangman, berdasarkan jumlah salah

void DeleteAtH(ListH *Lbenar, ListH LSoal, int indeks);
//prosedur untuk menghapus elemen ke-indeks

void InsertAtH(ListH *Lbenar, ListH LSoal, int indeks);
//prosedur untuk memasukkan elemen (pada indeks yang telah ditentukan) ke dalam list

void DigitBenar(ListH *LSoal, char huruf, ListH *Lsalah, ListH *Lbenar);
//prosedur untuk merubah tampilan dari '_' menjadi huruf yg ditebak (jika tebakan benar).
//prosedur ini juga akan memasukkan huruf yang tebakannya salah ke dalam list huruf yg salah.

void PrintListH(ListH L, int max);
//prosedur untuk menampilkan isi daripada ListH

void TampilanGame(ListH Lbenar, ListH Lsalah, int urutan, ListH LSoal);
//prosedur untuk menampilkan tampilan game

boolean isExistH(char huruf, ListH Lsalah, ListH Lbenar, ListH LSoal);
//fungsi untuk mencari huruf di dalam list. Fungsi akan mengembalikan true bila huruf dapat ditemukan.

void HangMan(int *skorhangman);
//prosedur utama dari game hangman

#endif
