#include "console.h"
#include "RNG.h"
#include "marvelsnap.h"
#include "dinerdash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void delay(int milli_seconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

void printDelay(char *daString, int lamaDelay)
{
    for (int i = 0; i < strLength(daString); i++)
    {
        printf("%c", daString[i]);
        delay(lamaDelay);
    }
}

void start(char * filename, ArrayDin *arraygame, boolean* fileopen){
    int n = 0;
    int i,j;
    int length = 0;
    char huruf;
    ElType kata;
    C_STARTKATA(filename, fileopen);
    if (*fileopen){
        printDelay("Memuat config.txt",25); printDelay("...\n",200);
        printf("KONFIGURASI AWAL BERHASIL! \n");
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
        printf("KONFIGURASI AWAL GAGAL!\n");
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
        printDelay("Memuat ",25); printDelay(filename,25); printDelay("...\n",200);
        printf("file %s berhasil dimuat!\n",filename);
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
        printf("DAFTAR COMMAND:\n");
        printDelay("1.  START - Melakukan konfigurasi sistem baru\n", 1);
        printDelay("2.  LOAD <namafile.txt> - Memuat konfigurasi pada SAVEFILE yang dipilih\n", 1);
        printDelay("3.  HELP - Menampilkan daftar command (perintah) yang dapat dipanggil\n", 1);
        printDelay("4.  QUIT - Mengakhiri dan keluar dari sistem\n", 1);
    }

    else{
        printf("DAFTAR COMMAND:\n");
        printDelay("1.  START - Melakukan konfigurasi sistem baru\n", 1);
        printDelay("2.  LOAD <namafile.txt> - Memuat konfigurasi pada SAVEFILE yang dipilih\n", 1);
        printDelay("3.  HELP - Menampilkan daftar command (perintah) yang dapat dipanggil\n", 1);
        printDelay("4.  QUIT - Mengakhiri dan keluar dari sistem\n", 1);
        printDelay("5.  SAVE <namafile.txt> - Melakukan penyimpanan konfigurasi pada file tertentu\n", 1);
        printDelay("6.  CREATE GAME - Membuat dan menambahkan game baru ke dalam daftar\n", 1);
        printDelay("7.  LIST GAME - Menampilkan daftar game yang dapat dimainkan\n", 1);
        printDelay("8.  DELETE GAME - Mengahpus suatu game dari dalam daftar\n", 1);
        printDelay("9.  QUEUE GAME - Menambahkan game tertentu ke dalam antrian permainan\n", 1);
        printDelay("10. PLAY GAME - Memulai permainan berdasarkan antrian teratas\n", 1);
        printDelay("11. SKIPGAME n - Melewati n banyak game dari dalam antrian dan memainkan game berikutnya.\n", 1);
    }
}

void CREATEGAME(ArrayDin *listgame){
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTKATAGAME();
    system("cls");
    char *permainan = toString(CKata);
    printDelay("Memcoba memasukkan ",25); printDelay(permainan,25); printDelay(" ke dalam list game",25); printDelay("...\n",200);
    if(isMemberArray(CKata,*listgame)){
        printf("Game %s sudah ada di dalam list\n",permainan);
    }
    else{
        InsertLast(listgame,CKata);
        printf("Game %s berhasil ditambahkan\n", permainan);
    }
}

void DELETEGAME(ArrayDin *listgame, Queue queuegame){
    int n;
    char * permainan;
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintArrayDin(*listgame);
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTKATAGAME();
    system("cls");
    if (IsNumber(CKata)){
        n = KataInt(CKata);
        if (n > 0 && n <= listgame->Neff){
            permainan = toString(listgame->A[n-1]);
            printDelay("Mencoba menghapus ",25);printDelay(permainan,25);printDelay(" dari list game",25);printDelay("...\n",200);
            if(n <= 5 || isMemberQueue(listgame->A[n-1], queuegame)){ //game ada di queue atau n <= 5
                if (n<=5){
                    printf("Game gagal dihapus (%s terdapat pada file konfigurasi)\n",permainan);
                }
                else{
                    printf("Game gagal dihapus (nomor game %s terdapat pada queue game)\n",permainan);
                }
            }
            else{
                DeleteAt(listgame,n-1);
                printf("Game %s berhasil dihapus\n",permainan);
            }
        }
        else{
            printDelay("Loading",25);printDelay("...\n",200);
            printf("Game gagal dihapus (nomor game %d tidak ditemukan)\n", n);
        }
    }
    else{
        printf("Input tidak valid\n");
    }
}

void LISTGAME(ArrayDin listgame){
    printf("Berikut adalah daftar list game anda:\n");
    PrintArrayDin(listgame);
}

void QUEUEGAME(ArrayDin listgame, Queue* queuegame){
    int n;
    char * permainan;
    ElType game;
    printf("Berikut adalah daftar antrian game-mu\n");
    displayQueue(*queuegame);
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintArrayDin(listgame);
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    STARTKATAGAME();
    system("cls");
    if (IsNumber(CKata)){
        n = KataInt(CKata);
        if (n <= listgame.Neff && n>0){
            game = listgame.A[n-1];
            permainan = toString(game);
            printDelay("Memasukan ",25);printDelay(permainan,25); printDelay(" ke dalam queue game ",25); printDelay("...\n",200);
            enqueue(queuegame,game);
            printf("Game berhasil ditambahkan ke antrian\n");
        }
        else{
            printDelay("Loading",25); printDelay("...\n",200);
            printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        }
    }

    else{
        printDelay("Loading",25); printDelay("...\n",200);
        printf("Input tidak valid\n");
    }
}

void PLAYGAME(Queue* queuegame)
{
    printf("Berikut adalah daftar Game-mu\n");
    displayQueue(*queuegame);
    ElType game;
    char *permainan;
    if (isEmpty(*queuegame)){
        printDelay("Loading",25);printDelay("...\n",200);
        printf("Antrian game anda kosong!\n");
    }
    else{
        dequeue(queuegame, &game);
        permainan = toString(game);
        printDelay("Loading ",25);
        printDelay(permainan,25);
        printDelay("..\n",200);
        system("cls");
        boolean game1 = compareWord(game, "RNG");
        boolean game2 = compareWord(game, "Diner DASH");
        boolean game3 = compareWord(game, "DINOSAUR IN EARTH");
        boolean game4 = compareWord(game, "RISEWOMAN");
        boolean game5 = compareWord(game, "EIFFEL TOWER");
        boolean game6 = compareWord(game, "MARVEL SNAP");
        if(game1)
        {
            RNG();
        }
        else if(game2)
        {
            dinerDASH();
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
        else if(game6){
            MARVELSNAP();
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
    char *permainan;

    while(i<num && !(isEmpty(*queuegame))){
        dequeue(queuegame,&game);
        i++;
    }

    if(isEmpty(*queuegame)){
        printDelay("Loading ",25);
        printDelay("...\n",200);
        printf("Antrian game anda kosong! (%d < %d) \n",i,num);
    }

    else{
        dequeue(queuegame, &game);
        permainan = toString(game);
        printDelay("Loading ",25);
        printDelay(permainan,25);
        printDelay("..\n",200);
        system("cls");
        boolean game1 = compareWord(game, "RNG");
        boolean game2 = compareWord(game, "Diner DASH");
        boolean game3 = compareWord(game, "DINOSAUR IN EARTH");
        boolean game4 = compareWord(game, "RISEWOMAN");
        boolean game5 = compareWord(game, "EIFFEL TOWER");
        boolean game6 = compareWord(game, "MARVEL SNAP");

        if(game1)
        {
            RNG();
        }
        else if(game2)
        {
            dinerDASH();
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
        else if(game6){
            MARVELSNAP();
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
        printDelay("Loading",25);printDelay("...\n",200);
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
        printDelay("Save data to ",25); printDelay(filename,25); printDelay("...\n",200);
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
            system("cls");
            if (compareWord(CKata, "Yes"))
            {
                printDelay("\nBMO: Masukkan nama save file anda!\n", 20);
                printf("File Name: ");
                STARTKATAGAME();
                system("cls");
                SAVE(CKata, listGame);
            }
            else if (compareWord(CKata, "No"))
            {
                printDelay("\nBMO: Progress anda tidak disimpan.\n", 20);
            }
            else
            {
                invalid_input = true;
                printDelay("BMO: Masukkan tidak dikenali. Mohon masukkan dengan format yang benar!\n", 10);
            }

        } while (invalid_input);
    }

    printDelay("BMO: BMO sangat senang bisa bermain denganmu! ^^\n", 20);
    printDelay("BMO: Let's play again so- ", 20);
    delay(200);
    printf("sometimes");
    delay(500);
    printDelay(", okay? ^^\n", 20);
    printDelay("BMO: Battery ", 20);
    delay(500);
    printf("low. ");
    printDelay("Shutdown", 20);
    printDelay("...\n", 200);
    delay(1500);
}

