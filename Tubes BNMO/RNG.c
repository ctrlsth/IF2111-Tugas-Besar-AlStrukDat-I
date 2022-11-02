#include <math.h>
#include <stdio.h>
#include <time.h>
#include "ADT MESIN KARAKTER/mesin_kar.h"
#include "boolean.h"

int acakAngka (){
    int BilRandom;
    srand(time(0));

    BilRandom = rand()%101;//buat bilangan random dengan maksimal angka yang keluar adalah 100
    return (BilRandom);
}

int skoring(){
    int tebakan;
    int jawaban;
    int skor = 100; //skor max 100 dan skor akan berkurang (-5) setiap user melakukan satu kesalahan
    boolean found = false;

    jawaban = acakAngka();
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.");
    scanf("Tebakan : %d", &tebakan);
    if (tebakan == jawaban){
        return skor;
    } else{
        while (skor >=0 && !found){
            if (tebakan > jawaban){
                printf("Lebih Kecil");
                skor = skor - 5;
                scanf("Tebakan : %d", &tebakan);
            } else if (tebakan < jawaban){
                printf("Lebih Besar");
                skor = skor - 5;
                scanf("Tebakan : %d", &tebakan);
            } else {
                printf("Ya, X adalah %d.", jawaban);
                found = true;
            }
        } 
        if (found){
            return skor;
        } else {
            return -999;
        }
    }
}

void klasifikasiWInLose (int skor){
    char resume;

    if (skor==-999){
        resume = 'Kalah';
    } else if (skor == 0) {
        resume = 'Hampir Banget Kalah'; //Masih menang, tapi di batas minimal skor (0)
    } else {
        resume = 'Menang';
    }
}
