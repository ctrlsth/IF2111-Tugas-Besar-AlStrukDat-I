#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "console.h"

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

void START(char *filename, TabWord *listGame, boolean *loaded)
{
    int n = 0;
    int i, j;
    int length = 0;
    char huruf;
    ElType kata;
    STARTWORD(filename, loaded);
    if (*loaded)
    {
        printf("KONFIGURASI AWAL BERHASIL!\n");
        if (!EndWord)
        {
            n = toInt(currentWord);
            // printf("Harusnya (5) : %d\n", n);
            ADVWORD();
            for (i = 0; i < n; i++)
            {
                InsertLast(listGame, currentWord);
                ADVWORD();
                // printWord(currentWord);
                // printf("\nPassed %d\n", i);
            }
        }
    }
    else
    {
        printf("KONFIGURASI AWAL GAGAL!\n");
    }
}

void LOAD(char *filename, TabWord *listGame, boolean *loaded)
{
    int i, j;
    int n = 0;
    int length = 0;
    int count = 0;
    char huruf;
    ElType kata;
    char loc[50] = "./data/";

    for (i = 7; i < strLength(filename) + 7; i++)
    {
        loc[i] = filename[i - 7];
    }
    loc[i] = '\0';

    STARTWORD(loc, loaded);
    if (*loaded)
    {
        printf("FILE %s BERHASIL DIMUAT!\n", filename);
        if (!EndWord)
        {
            n = toInt(currentWord);
            ADVWORD();
            for (i = 0; i < n; i++)
            {
                InsertLast(listGame, currentWord);
                ADVWORD();
            }
        }
    }
    else
    {
        printf("FILE %s TIDAK DITEMUKAN!\n", filename);
    }
}

void HELP(boolean loaded)
{
    printf("DAFTAR COMMAND:\n");
    printDelay("1.  START - Melakukan konfigurasi sistem baru\n", 1);
    printDelay("2.  LOAD <namafile.txt> - Memuat konfigurasi pada SAVEFILE yang dipilih\n", 1);
    printDelay("3.  HELP - Menampilkan daftar command (perintah) yang dapat dipanggil\n", 1);
    printDelay("4.  QUIT - Mengakhiri dan keluar dari sistem\n", 1);
    if (loaded)
    {
        printDelay("5.  SAVE <namafile.txt> - Melakukan penyimpanan konfigurasi pada file tertentu\n", 1);
        printDelay("6.  CREATE GAME - Membuat dan menambahkan game baru ke dalam daftar\n", 1);
        printDelay("7.  LIST GAME - Menampilkan daftar game yang dapat dimainkan\n", 1);
        printDelay("8.  DELETE GAME - Mengahpus suatu game dari dalam daftar\n", 1);
        printDelay("9.  QUEUE GAME - Menambahkan game tertentu ke dalam antrian permainan\n", 1);
        printDelay("10. PLAY GAME - Memulai permainan berdasarkan antrian teratas\n", 1);
        printDelay("11. SKIPGAME n - Melewati n banyak game dari dalam antrian dan memainkan game berikutnya.\n", 1);
    }
}

void LISTGAME(TabWord listGame)
{
    PrintTabWord(listGame);
}
void CREATEGAME(TabWord *listGame)
{
    printDelay("Masukkan nama game yang akan ditambahkan: ", 50);
    STARTCMD();
    InsertLast(listGame, currentCommand);
    printDelay("Game berhasil ditambahkan\n", 50);
}

void DELETEGAME(TabWord *listGame)
{
    LISTGAME(*listGame);
    printDelay("Masukkan nomor game yang akan dihapus: ", 50);
    STARTCMD();
    int number = toInt(currentCommand);
    number--;
    if (!(number >= 0 && number <= 4) && number <= listGame->Neff)
    {
        DeleteAt(listGame, number);
        printDelay("Game berhasil dihapus!\n", 50);
    }
    else
    {
        printDelay("Game gagal dihapus!\n", 50);
    }
}

void SAVE(char *filename, TabWord listGame)
{
    int i;
    FILE *savefile;
    char path[50] = "./data/";

    for (i = 7; i < strLength(filename) + 7; i++)
    {
        path[i] = filename[i - 7];
    }
    path[i] = '\0';

    savefile = fopen(path, "w+");
    // printf("Passed\n");
    if (savefile == NULL)
    {
        printf("\n------------------------------------------------\n");
        printf("Gagal membuka / membuat file. Silahkan coba lagi!\n");
        printf("-------------------------------------------------\n");
        delay(50);
    }
    else
    {
        // printf("Passed\n");
        char num[3];
        sprintf(num, "%d", Length(listGame));
        // printf("PassedX\n");
        fputs(num, savefile);
        // printf("PassedY\n");
        fputs("\n", savefile);
        // printf("PassedZ\n");
        for (i = 0; i < listGame.Neff; i++)
        {
            char *gamename = toString(Get(listGame, i));
            fputs(gamename, savefile);
            fputs("\n", savefile);
        }

        fclose(savefile);

        printf("\n-------------------------------\n");
        printf("Berhasil menyimpan progress. ^^\n");
        printf("--------------------------------\n");
    }
}

void QUIT(TabWord listGame)
{
    boolean invalid_input;
    if (!IsEmpty(listGame))
    {
        printDelay("BMO: Apakah anda ingin menyimpan progress anda?\n", 20);
        do
        {
            invalid_input = false;
            printf("** Hint: Ketika 'Ya' jika ingin menyimpan atau 'Tidak' jika ingin membuang **\n");
            printf("You: ");
            STARTCMD();
            if (compareWord(currentCommand, "Ya"))
            {
                printDelay("\nBMO: Masukkan nama save file anda!\n", 20);
                printf("Nama file: ");
                STARTCMD();
                SAVE(currentCommand.TabChar, listGame);
            }
            else if (compareWord(currentCommand, "Tidak"))
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