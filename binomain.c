#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/mesinkata.h"
#include "src/ADT/array.h"
#include "src/ADT/queue.h"
#include "src/boolean.h"
#include "src/console.h"

void unknownCommand()
{
    printf("BMO: Perintah tidak dikenali! Tolong masukan perintah yang valid!\n");
    printf("** Hint: Ketik \"HELP\" untuk melihat perintah **\n");
}

int main()
{
    /* *** INISIALISASI *** */
    Queue queueGame; CreateQueue(&queueGame);
    TabWord listGame; MakeTabWord(&listGame);
    TabWord listCommand; MakeTabWord(&listCommand);

    boolean active = true;
    boolean loaded = false;

    system("cls");

    /* *** MAIN LOOP *** */
    do
    {
        printf("\nENTER COMMAND: ");
        STARTCMD();

        printf("BMO: Mengenali perintah");
        printDelay("...\n", 200);

        while (!EndWord)
        {
            InsertLast(&listCommand, currentCommand);
            ADVCMD();
        }

        if (compareWord(Get(listCommand, 0), "START"))
        {
            if (!loaded)
            {
                START("data/config.txt", &listGame, &loaded);
            }
            else
            {
                printf("BMO: Sistem sudah terkonfigurasi.\n");
                printf("** Hint: Untuk memulai konfigurasi baru, silahkan \"EXIT\" terlebih dahulu **\n");
            }
        }
        else if (compareWord(Get(listCommand, 0), "LOAD"))
        {
            if (!loaded)
            {
                char* loadfile = toString(Get(listCommand, 1));
                LOAD(loadfile, &listGame, &loaded);
            }
            else
            {
                printf("BMO: Sistem sudah terkonfigurasi. Silahkan \"EXIT\" terlebih dahulu untuk memulai konfigurasi baru.\n");
            }
        }
        else if (compareWord(Get(listCommand, 0), "HELP"))
        {
            HELP(loaded);
        }
        else if (compareWord(Get(listCommand, 0), "QUIT"))
        {
            QUIT(listGame);
            active = false;
        }
        else if (compareWord(Get(listCommand, 0), "CREATE") && compareWord(Get(listCommand, 1), "GAME"))
        {
            (loaded) ? CREATEGAME(&listGame) : unknownCommand();
        }
        else if (compareWord(Get(listCommand, 0), "SAVE"))
        {
            if (loaded)
            {
                char* savefile = toString(Get(listCommand, 1));
                SAVE(savefile, listGame);
            }
            else
            {
                unknownCommand();
            }
        }
        else if (compareWord(Get(listCommand, 0), "LIST") && compareWord(Get(listCommand, 1), "GAME"))
        {
            (loaded) ? LISTGAME(listGame) : unknownCommand();
        }
        else if (compareWord(Get(listCommand, 0), "DELETE") && compareWord(Get(listCommand, 1), "GAME"))
        {
            (loaded) ? DELETEGAME(&listGame) : unknownCommand();
        }
        else if (compareWord(Get(listCommand, 0), "QUEUE") && compareWord(Get(listCommand, 1), "GAME"))
        {
            // (loaded) ? QUEUE() : unknownCommand();
            printf("Passed QueueGame.\n");
        }
        else if (compareWord(Get(listCommand, 0), "PLAY") && compareWord(Get(listCommand, 1), "GAME"))
        {
            // (loaded) ? PLAY() : unknownCommand();
            printf("Passed PlayGame.\n");
        }
        else if (compareWord(Get(listCommand, 0), "SKIPGAME"))
        {
            if (loaded)
            {
                // SKIPGAME(Get(listCommand, 1));
                printf("Passed Skip Game.\n");
            }
            else
            {
                unknownCommand();
            }
        }
        else
        {
            unknownCommand();
        }

        DeallocateTabWord(&listCommand);
        MakeTabWord(&listCommand);

    } while (active);

    return 0;
}