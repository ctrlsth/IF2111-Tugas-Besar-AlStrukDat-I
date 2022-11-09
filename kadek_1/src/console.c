#include "console.h"
#include <stdio.h>
#include <stdlib.h>

void start(char * filename, ArrayDin *arraygame, boolean* fileopen){
    int n = 0;
    int i,j;
    int length = 0;
    char huruf;
    ElType kata;
    C_STARTKATA(filename, fileopen);
    if (*fileopen){
        printf("START FILE BERHASIL! \n");
        if (!EndKata){
            n = KataInt(CKata);
            C_ADVKATA();
            for(i=0;i<n;i++){
                kata = CKata;
                InsertLast(arraygame,kata);
                C_ADVKATA();
            }
        }
    }

    else{
        printf("START FILE GAGAL!\n");
    }
}

void LOAD(char * filename, ArrayDin *arraygame, boolean *fileopen){
    int n = 0;
    int i,j;
    int length = 0;
    int count = 0;
    char huruf;
    ElType kata;
    char *loc = "data/";
    char *fileloc = strConcat(loc,filename);
    C_STARTKATA(fileloc, fileopen);
    if (*fileopen){
        printf("LOAD FILE BERHASIL!\n");
        if (!EndKata){
            n = KataInt(CKata);
            C_ADVKATA();
            for(i=0;i<n;i++){
                kata = CKata;
                InsertLast(arraygame,kata);
                C_ADVKATA();
            }
        }
    }
    else{
        printf("LOAD FILE GAGAL!\n");
    }
}

void help(boolean mainmenu){
    if (!mainmenu){
        printf("START - \n");
        printf("LOAD <namafile.txt> - \n");
        printf("QUIT - \n");
    }

    else{
        printf("LIST GAME - \n");
    }
}

void QUEUEGAME(ArrayDin listgame, Queue* queuegame){
    int n;
    ElType game;
    printf("Berikut adalah daftar antrian game-mu\n");
    displayQueue(*queuegame);
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintArrayDin(listgame);
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    STARTKATAGAME();
    if (IsNumber(CKata)){
        n = KataInt(CKata);
        if (n <= listgame.Neff){
            game = listgame.A[n-1];
            enqueue(queuegame,game);
            printf("Game berhasil ditambahkan ke antrian\n");
        }
        else{
            printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        }
    }

    else{
        printf("Input tidak valid\n");
    }
}

void PLAYGAME(Queue* queuegame)
{
    displayQueue(*queuegame);
    ElType game;
    if (isEmpty(*queuegame)){
        printf("Antrian game anda kosong!\n");
    }
    else{
        dequeue(queuegame, &game);
        printf("Loading ");
        printKata(game);
        printf("..\n");
        boolean game1 = compareWord(game, "RNG");
        boolean game2 = compareWord(game, "Diner DASH");
        boolean game3 = compareWord(game, "DINOSAUR IN EARTH");
        boolean game4 = compareWord(game, "RISEWOMAN");
        boolean game5 = compareWord(game, "EIFFEL TOWER");
        if(game1)
        {
            printf("MAIN RNG\n");
        }
        else if(game2)
        {
            printf("MAIN Diner DASH\n");
        }
        else if(game3)
        {
            printf("MAIN DINOSAUR IN EARTH\n");
        }
        else if(game4)
        {
            printf("MAIN RISEWOMAN\n");
        }
        else if(game5)
        {
            printf("EIFFEL TOWER\n");
        }
        else
        {
            printf("Total score = 10\n");
        }
    }
}

void SKIPGAME(Queue* queuegame, int num)
{
    displayQueue(*queuegame);
    int i = 0;
    ElType game;

    while(i<num && !(isEmpty(*queuegame))){
        dequeue(queuegame,&game);
        i++;
    }

    if(isEmpty(*queuegame)){
        printf("Antrian game anda kosong!\n");
    }

    else{
        dequeue(queuegame, &game);
        printf("Loading ");
        printKata(game);
        printf("..\n");
        boolean game1 = compareWord(game, "RNG");
        boolean game2 = compareWord(game, "Diner DASH");
        boolean game3 = compareWord(game, "DINOSAUR IN EARTH");
        boolean game4 = compareWord(game, "RISEWOMAN");
        boolean game5 = compareWord(game, "EIFFEL TOWER");
        if(game1)
        {
            printf("MAIN RNG\n");
        }
        else if(game2)
        {
            printf("MAIN Diner DASH\n");
        }
        else if(game3)
        {
            printf("MAIN DINOSAUR IN EARTH\n");
        }
        else if(game4)
        {
            printf("MAIN RISEWOMAN\n");
        }
        else if(game5)
        {
            printf("EIFFEL TOWER\n");
        }
        else
        {
            printf("Total score = 10\n");
        }
    }
}