#include "ADT/array.h"
#include "ADT/mesinkata.h"
#include <stdio.h>
#include <stdlib.h>


void listgame(TabWord listgame){
    printf("Berikut adalah daftar game yang tersedia");
    PrintTabWord (listgame);
}

void creategame(TabWord *listgame){
    printf("Masukkan nama game yang akan ditambahkan: ");

    // data newgame = {
    //     name : "",
    //     deletable : true,
    // };

    STARTCMD();
    InsertLast(listgame,currentCommand);
    //masukin nama game ke newgame
    printf("Game berhasil ditambahkan\n");
}
// data fixedGames[] = {
//     {name : "RNG", deletable : false},
//     {name : "Diner DASH", deletable : false},
//     {name : "DINOSAUR IN EARTH", deletable : false},
//     {name : "RISEWOMAN", deletegame : false},
//     {name : "EIFFEL TOWER", deletable : false}
// };

void deletegame(TabWord *listgame){
    listgame(*listgame);
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCMD();
    int number = atoi(&currentCommand);
    number = number-1;
    if (!(number >=0 && number <=4)){
        DeleteAt(listgame, number);
        printf("Game berhasil dihapus");
    }
    else{
        printf("Game gagal dihapus");
    }
}
