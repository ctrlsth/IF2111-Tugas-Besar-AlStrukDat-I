#include "console.h"
#include "RNG.h"
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
        printf("file %s tidak ditemukan \n",filename);
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

void CREATEGAME(ArrayDin *listgame){
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTKATAGAME();
    if(isMemberArray(CKata,*listgame)){
        printf("Game ");
        printKata(CKata);
        printf(" sudah ada di dalam list\n");
    }
    else{
        InsertLast(listgame,CKata);
        printf("Game berhasil ditambahkan\n");
    }
}

void DELETEGAME(ArrayDin *listgame, Queue queuegame){
    int n;
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintArrayDin(*listgame);
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTKATAGAME();
    if (IsNumber(CKata)){
        n = KataInt(CKata);
        if (n > 0 && n <= listgame->Neff){
            if(n <= 5 || isMemberQueue(listgame->A[n-1], queuegame)){ //game ada di queue atau n <= 5
                if (n<=5){
                    printf("Game gagal dihapus (nomor game %d terdapat pada file konfigurasi)\n",n);
                }
                else{
                    printf("Game gagal dihapus (nomor game %d terdapat pada queue game)\n",n);
                }
            }
            else{
                DeleteAt(listgame,n-1);
                printf("Game berhasil dihapus\n");
            }
        }
        else{
            printf("Game gagal dihapus (nomor game %d tidak ditemukan)\n", n);
        }
    }
    else{
        printf("Input tidak valid\n");
    }
}

void LISTGAME(ArrayDin listgame){
    printf("list game anda:\n");
    PrintArrayDin(listgame);
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
        if (n <= listgame.Neff && n>0){
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
    printf("Berikut adalah daftar Game-mu\n");
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
            RNG();
        }
        else if(game2)
        {
            printf("MAIN Diner DASH\n");
        }
        else if(game3)
        {
            printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
        }
        else if(game4)
        {
            printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
        }
        else if(game5)
        {
            printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
        }
        else
        {
            int skor = acakAngka();
            printf("GAME OVER\n");
            printf("Total score = %d\n",skor);
        }
    }
}

void SKIPGAME(Queue* queuegame, int num)
{
    printf("Berikut adalah daftar Game-mu\n");
    displayQueue(*queuegame);
    int i = 0;
    ElType game;

    while(i<num && !(isEmpty(*queuegame))){
        dequeue(queuegame,&game);
        i++;
    }

    if(isEmpty(*queuegame)){
        printf("Antrian game anda kosong! (%d < %d) \n",i,num);
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
            RNG();
        }
        else if(game2)
        {
            printf("MAIN Diner DASH\n");
        }
        else if(game2)
        {
            printf("MAIN Diner DASH\n");
        }
        else if(game3)
        {
            printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
        }
        else if(game4)
        {
            printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
        }
        else if(game5)
        {
            printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
        }
        else
        {
            int skor = acakAngka();
            printf("GAME OVER\n");
            printf("Total score = %d\n",skor);
        }
    }
}

void SAVE(Kata file, ArrayDin listGame)
{

    int i;
    FILE *savefile;
    char* path = "data/";
    char *filename = toString(file);
    char * fileloc = strConcat(path,filename);

    // for (i = 7; i < strLength(filename) + 7; i++)
    // {
    //     path[i] = filename[i-7];
    // }
    savefile = fopen(fileloc, "w+");
    if (savefile == NULL)
    {
        printf("\n----------------------------\n");
        printf("Error opening the file %s\n", filename);
        printf("----------------------------\n\n");
    }
    else
    {
        char num[3];
        sprintf(num, "%d", listGame.Neff);
        fputs(num, savefile);
        fputs("\n", savefile);
        for (i = 0; i < listGame.Neff; i++)
        {
            char *gamename = toString(listGame.A[i]);
            fputs(gamename, savefile);
            if (i != listGame.Neff -1){
                fputs("\n", savefile);
            }
        }

        fclose(savefile);

        printf("\n---------------------------------------\n");
        printf("Your progress is saved successfully. ^^\n");
        printf("---------------------------------------\n\n");
    }
}

void QUIT(ArrayDin listGame)
{
    boolean invalid_input;
    if (!IsEmpty(listGame))
    {
        printf("BMO: Do you wish to save your current progress?\n");
        do
        {
            invalid_input = false;
            printf("** Hint: Type 'Yes' to save; Type 'No' to discard **\n");
            printf("You: ");
            STARTKATAGAME();
            if (compareWord(CKata, "Yes"))
            {
                printf("\nBMO: Please name your save file!\n");
                printf("File Name: ");
                STARTKATAGAME();
                SAVE(CKata, listGame);
            }
            else if (compareWord(CKata, "No"))
            {
                printf("\nBMO: Your progress is discarded.\n");
            }
            else
            {
                invalid_input = true;
                printf("BMO: Unrecognized input. Please use the correct format!\n");
            }

        } while (invalid_input);
    }

    printf("BMO: It's been a fun journey playing with You. ^^\n");
    printf("BMO: But I think i- it's be --en t- t-- too f-- unn\n");
    printf("BMO: Battery low. Shutdown.\n");
}

