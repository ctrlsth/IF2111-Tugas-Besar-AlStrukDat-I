#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "boolean.h"
#include "console.h"
#include "Game/dinerdash.h"
#include "Game/RNG.h"
#include "Game/marvelsnap.h"

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

void LOAD(char *filename, TabWord *listGame, boolean *loaded, Stack *stackHistory, ListOfSet *listPlayer, ListOfMap *scoreBoard)
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
        if (!EndWord)
        {
            int iteration = 1;
            n = toInt(currentWord); // Memiliki nilai banyak game yang berada dalam savefile.
            scoreBoard->Num = n;
            listPlayer->Num = n;

            // listGame dan History
            while (iteration != 3)
            {
                ADVWORD();
                for (i = 0; i < n; i++)
                {
                    if (iteration == 1)
                    {
                        InsertLast(listGame, currentWord);
                    }
                    else if (iteration == 2)
                    {
                        Push(stackHistory, currentWord);
                    }

                    ADVWORD();
                }
                n = toInt(currentWord);
                iteration++;
            }

            printf("Passed\n");

            // ScoreBoard
            int idx = 0;
            while (!EndWord)
            {
                n = toInt(currentWord);
                Set *currentSet = &(listPlayer->GameSet[idx]);
                Map *currentMap = &(scoreBoard->board[idx]);
                printf("Passed Declaration\n");

                ADVWORD();
                for (i = 0; i < n; i++)
                {
                    // Melakukan separasi antara nama dan skor
                    Word Name, Score;
                    binSep(currentWord, &Name, &Score, ' ');
                    printf("Passed Sep\n");

                    // Memasukkan nama pada Set dan Skor pada Map
                    InsertSetEl(currentSet, Name);
                    printf("Passed Set\n");
                    MapValIns(currentMap, Name, toInt(Score));
                    printf("Passed Map\n");

                    ADVWORD();
                }

                idx++;
            }

            printf("FILE %s BERHASIL DIMUAT!\n", filename);
        }
        else
        {
            printf("FILE %s KOSONG!\n", filename);
            (*loaded) = false;
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
        printDelay("8.  DELETE GAME - Menghapus suatu game dari dalam daftar\n", 1);
        printDelay("9.  QUEUE GAME - Menambahkan game tertentu ke dalam antrian permainan\n", 1);
        printDelay("10. PLAY GAME - Memulai permainan berdasarkan antrian teratas\n", 1);
        printDelay("11. SKIP GAME <n> - Melewati n banyak game dari dalam antrian dan memainkan game berikutnya.\n", 1);
    }
}

void LISTGAME(TabWord listGame)
{
    PrintTabWord(listGame);
}

void CREATEGAME(TabWord *listGame)
{
    currentCommand.Length = 0;
    printDelay("Masukkan nama game yang akan ditambahkan: ", 50);
    STARTCMD(true);
    int i = 0;
    boolean not_exist = true;
    while (i < Length((*listGame)) && not_exist)
    {
        if (compare2Word(Get(*listGame, i), currentCommand))
        {
            not_exist = false;
        }
        i++;
    }
    if (not_exist)
    {
        if (currentCommand.Length == 0)
        {
            printDelay("Mohon masukkan masukan yang valid!\n", 50);
        }
        else
        {
            InsertLast(listGame, currentCommand);
            printDelay("Game berhasil ditambahkan!\n", 50);
        }
    }
    else
    {
        printDelay("Game sudah terdaftar dalam \"LIST GAME\"!\n", 50);
    }
    
}

void DELETEGAME(TabWord *listGame, Queue queueGame)
{
    LISTGAME(*listGame);
    printf("\n** Hint: Game yang dapat dihapus adalah Game dengan nomor urut > 6 **\n");
    printDelay("Masukkan nomor game yang akan dihapus: ", 20);
    STARTCMD(false);
    if (isNumber(currentCommand))
    {
        int number = toInt(currentCommand) - 1;
        if (number > 5 && number < listGame->Neff)
        {   
            if (isInQueue(queueGame, Get(*listGame, number)))
            {
                printDelay("\nGagal Menghapus Game: Game terdapat dalam antrian!\n", 20);
            }
            else
            {
                DeleteAt(listGame, number);
                printDelay("\nGame Berhasil Dihapus!\n", 20);
            }
        }
        else
        {
            printDelay("\nGagal Menghapus Game: Masukan berada di luar rentang!\n", 50);
        }
    }
    else
    {
            printDelay("\nMohon masukkan masukan yang valid!\n", 50);
    }
}

void QUEUEGAME(TabWord listGame, Queue *queueGame)
{
    int OGLength = length(*queueGame);
    displayQueue(*queueGame);
    LISTGAME(listGame);
    printDelay("Nomor Game yang mau ditambahkan ke antrian : ", 50);
    STARTCMD(false);
    if (isNumber(currentCommand))
    {
        int i = toInt(currentCommand) - 1;
        if (i >= 0 && i < Length(listGame))
        {
            enqueue(queueGame, Get(listGame, i));
        }
        if (OGLength < length(*queueGame))
        {
            printDelay("Game berhasil ditambahkan ke dalam daftar antrian!\n", 50);
        }
        else
        {
            printDelay("Masukan berada di luar rentang \"LIST GAME\".\n", 50);
            printDelay("Penambahan Game pada daftar antrian dibatalkan.\n", 50);
        }
    }
    else
    {
        printDelay("Mohon masukkan masukan yang valid!\n", 50);
    }
}

void PLAYGAME(TabWord listGame, Queue *queueGame)
{
    if (isEmpty(*queueGame))
    {
        printDelay("BMO: Antrian sama Dompet kamu kok mirip yaa? ^^\n", 50);
        printf("** Hint: Tambahkan Game dalam antrian menggunakan \"QUEUE GAME\" **\n");
    }
    else
    {
        ElType Game;
        dequeue(queueGame, &Game);
        
        char* GameName = toString(Game);
        printDelay("Loading ", 100);
        printDelay(GameName, 100);
        printDelay("...\n", 500);

        int i = 0;
        boolean whatGame = true;
        while (whatGame && i < Length(listGame))
        {
            if (compare2Word(Game, Get(listGame, i)))
            {
                whatGame = false;
            }
            i++;
        }

        if (!whatGame)
        {
            if (i == 1)
            {
                system("cls");
                RNG();
            }
            else if (i == 2)
            {
                system("cls");
                dinerDASH();
            }
            else if (i >= 3 && i <= 5)
            {
                printDelay(GameName, 50);
                printDelay(" masih dalam maintenance.\n", 50);
                printDelay("Silahkan pilih game lainnya!\n", 50);
            }
            else if (i == 6)
            {
                system("cls");
                MARVELSNAP();
            }
            else
            {
                int score = rand();
                printDelay("[ GAME OVER ]\n", 50);
                printDelay("[ SCORE: ", 50);
                printf("%d ", score);
                printDelay("]\n", 50);
            }
        }
        else
        {
            printDelay("Game ", 50);
            printDelay(GameName, 50);
            printDelay(" tidak terdaftar dalam \"LIST GAME\"\n", 50);
            printDelay("Silahkan pilih game lainnya!\n", 50);
        }
    }
}

void SKIPGAME(TabWord listGame, Queue *queueGame, int num)
{
    displayQueue(*queueGame);
    if (!isEmpty(*queueGame))
    {
        printDelay("Skipping ", 5);
        printf("%d ", num);
        printDelay("games", 5);
        ElType Game;
        for (int i = 0; i < num; i++)
        {
            printDelay("...", 500);
            if (!isEmpty(*queueGame)) 
            {
                dequeue(queueGame, &Game);
            }
            printf("\b\b\b");
            printf("   ");
            printf("\b\b\b");
        }
        printDelay("...\n", 500);
        PLAYGAME(listGame, queueGame);
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
        printf("------------------------------------------------\n");
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
            if (i != listGame.Neff -1)
            {
                fputs("\n", savefile);
            }
        }

        fclose(savefile);

        printf("\n-------------------------------\n");
        printf("Berhasil menyimpan progress. ^^\n");
        printf("-------------------------------\n");
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
            STARTCMD(false);
            if (compareWord(currentCommand, "Ya"))
            {
                printDelay("\nBMO: Masukkan nama save file anda!\n", 20);
                printf("Nama file: ");
                STARTCMD(false);
                char *savefile = toString(currentCommand);
                SAVE(savefile, listGame);
            }
            else if (compareWord(currentCommand, "Tidak"))
            {
                printDelay("\nBMO: Progress anda tidak disimpan.\n", 20);
            }
            else
            {
                invalid_input = true;
                printDelay("\nBMO: Masukkan tidak dikenali. Mohon masukkan dengan format yang benar!\n", 10);
            }

        } while (invalid_input);
    }

    printDelay("\nBMO: BMO sangat senang bisa bermain denganmu! ^^\n", 20);
    printDelay("BMO: Let's play again so- ", 20);
    delay(400);
    printf("\b\bmetimes");
    delay(500);
    printDelay(", okay? ^^\n", 20);
    printDelay("BMO: Battery ", 20);
    delay(500);
    printf("low. ");
    printDelay("Shutdown", 20);
    printDelay("...\n\n", 200);
    delay(1500);
}

void SCOREBOARD(ListOfSet listPlayer, ListOfMap scoreBoard, TabWord listGame)
{
    int j = 0;
    while (j < listPlayer.Num)
    {
        Set playerSet = listPlayer.GameSet[j];
        Map scoreMap = scoreBoard.board[j];

        printf("**** SCOREBOARD GAME ");
        printWord(listGame.TW[j]);
        printf(" ****\n");
        printf("-------------------------------------------\n");
        printf("| NAMA               | SKOR               |\n");
        printf("-------------------------------------------\n");
        int i;
        for (i = 0; i < playerSet.Count; i++)
        {
            printf("| ");
            Word player = playerSet.PlayerName[i];
            printWord(player);
            for (int j = 0; j < (19 - player.Length); j++)
            {
                printf(" ");
            }

            int skor = Value(scoreMap, player);
            int countDigit = (skor == 0) ? 1 : log10(skor) + 1;
            printf("| %d", skor);
            for (int j = 0; j < (19 - countDigit); j++)
            {
                printf(" ");
            }

            printf("|\n");
        }

        if (playerSet.Count == 0)
        {
            printf("|            SCOREBOARD KOSONG            |\n");
        }
        printf("-------------------------------------------\n\n");

        j++;
    }
}

void RESETSB(ListOfSet *listPlayer, ListOfMap *scoreBoard, TabWord listGame)
{
    int i;
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    for (i = 0; i < listGame.Neff; i++)
    {
        printf("%d. ", i + 1);
        printWord(listGame.TW[i]);
        printf("\n");
    }
    printf("\n");

    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    STARTCMD(false);
    printf("\n");
    if (!isNumber(currentCommand))
    {
        printf("MASUKAN TIDAK VALID.\n");
        printf("RESET SCOREBOARD DIBATALKAN.\n");
    }
    else
    {
        int n = toInt(currentCommand);
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ");
        if (n == 0)
        {
            printf("ALL");
        }
        else
        {
            printWord(listGame.TW[n - 1]);
        }

        printf(" (YA/TIDAK)? ");
        STARTCMD(false);
        if (compareWord(currentCommand, "YA"))
        {
            if (n == 0)
            {
                CreateEmptyMapList(scoreBoard);
                CreateEmptySetList(listPlayer);
            }
            else
            {
                CreateEmptyMap(&(scoreBoard->board[n - 1]));
                CreateEmptySet(&(listPlayer->GameSet[n - 1]));
            }

            printf("\nSCOREBOARD BERHASIL DI RESET!\n");
        }
        else if (compareWord(currentCommand, "TIDAK"))
        {
            printf("RESET SCOREBOARD DIBATALKAN.\n");
        }
        else
        {
            printf("MASUKAN TIDAK VALID.\n");
            printf("RESET SCOREBOARD DIBATALKAN.\n");
        }
    }
}

void UPDATESB(int score, Set *gamePlayers, Map *playerScores)
{
    // Check apakah sudah berada dalam set
    UPPER(&currentCommand);
    while (IsSetMember((*gamePlayers), currentCommand))
    {
        printf("Nama Sudah Terdaftar dalam SCOREBOARD.\n");
        printf("Harap masukkan Nama lainnya!\n");
        printf("Masukkan Nama: ");
        STARTCMD(false);
        UPPER(&currentCommand);
    }

    printf("Berhasil Menambahkan Data dalam SCOREBOARD!\n");
    InsertSetEl(gamePlayers, currentCommand);
    MapValIns(playerScores, currentCommand, score);
    SortByVal(playerScores);
    SortSetByMap(gamePlayers, (*playerScores));
}