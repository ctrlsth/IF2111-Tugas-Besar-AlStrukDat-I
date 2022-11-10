#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "console.h"

void delay_hundredth_sec(int lamaDelay)
{
    int milli_seconds = 10 * lamaDelay;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

void printDelay(char *daString)
{
    for (int i = 0; i < strLength(daString); i++)
    {
        printf("%c", daString[i]);
        delay_hundredth_sec(5);
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
    printf("1. START - Melakukan konfigurasi sistem baru\n");
    printf("2. LOAD <namafile.txt> - Memuat konfigurasi pada SAVEFILE yang dipilih\n");
    printf("3. HELP - Menampilkan daftar command (perintah) yang dapat dipanggil\n");
    printf("4. EXIT - Mengakhiri dan keluar dari sistem\n");
    if (loaded)
    {
        printf("5. SAVE <namafile.txt> - Melakukan penyimpanan konfigurasi pada file tertentu\n");
        printf("6. CREATE GAME - Membuat dan menambahkan game baru ke dalam daftar\n");
        printf("7. LIST GAME - Menampilkan daftar game yang dapat dimainkan\n");
        printf("8. DELETE GAME - Mengahpus suatu game dari dalam daftar\n");
        printf("9. QUEUE GAME - Menambahkan game tertentu ke dalam antrian permainan\n");
        printf("10. PLAY GAME - Memulai permainan berdasarkan antrian teratas\n");
        printf("11. SKIPGAME <banyak-skip> - Melewati <banyak-skip> game dari dalam antrian dan memainkan game berikutnya.\n");
    }
}

void LISTGAME(TabWord listGame)
{
    PrintTabWord(listGame);
}
void CREATEGAME(TabWord *listGame)
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTCMD();
    InsertLast(listGame, currentCommand);
    printf("Game berhasil ditambahkan\n");
}

void DELETEGAME(TabWord *listGame)
{
    LISTGAME(*listGame);
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCMD();
    int number = toInt(currentCommand);
    number--;
    if (!(number >= 0 && number <= 4) && number <= listGame->Neff)
    {
        DeleteAt(listGame, number);
        printf("Game berhasil dihapus!\n");
    }
    else
    {
        printf("Game gagal dihapus!\n");
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
    printf("Passed\n");
    if (savefile == NULL)
    {
        printf("\n------------------------------\n");
        printf("Error opening the file %s\n", filename);
        printf("------------------------------\n\n");
    }
    else
    {
        printf("Passed\n");
        char num[2];
        sprintf(num, "%d", Length(listGame));
        printf("PassedX\n");
        fputs(num, savefile);
        printf("PassedY\n");
        fputs("\n", savefile);
        printf("PassedZ\n");
        for (i = 0; i < listGame.Neff; i++)
        {
            char *gamename = toString(Get(listGame, i));
            fputs(gamename, savefile);
            fputs("\n", savefile);
        }

        fclose(savefile);

        printf("\n---------------------------------------\n");
        printf("Your progress is saved successfully. ^^\n");
        printf("---------------------------------------\n\n");
    }
}

void QUIT(TabWord listGame)
{
    boolean invalid_input;
    if (!IsEmpty(listGame))
    {
        printDelay("BMO: Do you wish to save your current progress?\n");
        do
        {
            invalid_input = false;
            printf("** Hint: Type 'Yes' to save; Type 'No' to discard **\n");
            printf("You: ");
            STARTCMD();
            if (compareWord(currentCommand, "Yes"))
            {
                printDelay("\nBMO: Please name your save file!\n");
                printf("File Name: ");
                STARTCMD();
                SAVE(currentCommand.TabChar, listGame);
            }
            else if (compareWord(currentCommand, "No"))
            {
                printDelay("\nBMO: Your progress is discarded.\n");
            }
            else
            {
                invalid_input = true;
                printDelay("BMO: Unrecognized input. Please use the correct format!\n");
            }

        } while (invalid_input);
    }

    char byeline[] = "BMO: It's been a fun journey playing with You. ^^\nBMO: But I think it's been t- t-too fu --n\nBMO: Battery low. Shutdown.\n";
    printDelay(byeline);
    delay_hundredth_sec(150);
}