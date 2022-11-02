#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADT MESIN KARAKTER/mesin_kar.h"
#include "boolean.h"

int acakAngka();
//mengirimkan sebuah bilangan acak dengan range angka keluar x>=0 dan x<=100

int skoring();
//mengirimkan sebuah hasil dari permainan. opsi angka yang muncul adalah skor>=0 atau skor ==-999
//fungsi ini merupakan sebuah fungsi utama pada case RNG ini
//Skor maksimal dari pemain adalah 100, skor akan berkurang (-5) setiap kali pemain melakukan kesalahan

void klasifikasiWInLose(int skor);
//procedure tambahan yang dapat digunakan untuk mengklasifikasikan hasil
//Jika hasil != -999, maka dapat disimpulkan bahwa permainan terhitung menang
