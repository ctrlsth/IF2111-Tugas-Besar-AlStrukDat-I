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

void ASCIIArt()
{
    printf(
    " ________  _____ ______   _______  ___  ________	    _____________    Z         \n"
    "|\\   __  \\|\\   _ \\  __  \\|\\    _  \\\\\\  \\|\\   __  \\	   | ___________ |  z         \n"
    "\\ \\  \\|\\ /\\ \\  \\\\\\__\\ \\  \\ \\   \\\\  \\\\\\  \\ \\  \\|\\  \\        ||  -  o  -  || z           \n"
    " \\ \\   __  \\ \\  \\\\|__| \\  \\ \\   \\\\   \\\\  \\ \\  \\\\\\  \\	   ||___________||      \n"
    "  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\\\\\   \\\\  \\ \\  \\\\\\  \\     /|             |\\       \n"
    "   \\ \\_______\\ \\__\\    \\ \\__\\ \\__\\\\\\_______\\ \\_______\\   / |  DaBinomo!  | \\       \n"
    "    \\|_______|\\|__|     \\|__|\\|__|\\|_______|\\|_______|	   |___O_____O___|            \n"
    "\n"
    );
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
    ASCIIArt();
    printf("You: ");
    delay(500);
    printf("* pressed the power button *\n");
    delay(1000);
    printf("BMO: ");
    printDelay("ZzZzzzzZZzZZZzzZzzzzZZ", 50);
    printDelay("...\n", 500);
    printf("BMO: ");
    printDelay("ZZzz... ", 100);
    printDelay("Hmmm? ", 50);
    delay(2000);
    printDelay("Huhh???\n", 50);
    delay(2000);
    printf("BMO: ");
    printDelay("Ohh! Hai! ", 25);
    delay(1000);
    printDelay("Maaf Baru Bangun :'\n", 25);
    delay(1500);
    printf("BMO: ");
    printDelay("Let's play together!! ^^\n", 25);
    delay(500);

    /* *** MAIN LOOP *** */
    do
    {
        printf("\nENTER COMMAND: ");
        STARTCMD(false);

        printf("BMO: Mengenali perintah");
        printDelay("...\n", 200);

        while (!EndWord)
        {
            InsertLast(&listCommand, currentCommand);
            ADVCMD(false);
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
                printf("** Hint: Untuk memulai konfigurasi baru, silahkan \"QUIT\" terlebih dahulu **\n");
            }
        }
        else if (compareWord(Get(listCommand, 0), "LOAD"))
        {
            if (!loaded)
            {
                if (Length(listCommand) == 2)
                {
                    char* loadfile = toString(Get(listCommand, 1));
                    LOAD(loadfile, &listGame, &loaded);
                }
                else
                {
                    printf("Mohon masukkan dengan format yang benar!\n");
                    printf("** Hint: Ketik \"HELP\" untuk melihat perintah **\n");
                }
                
            }
            else
            {
                printf("BMO: Sistem sudah terkonfigurasi.\n");
                printf("** Hint: Untuk memulai konfigurasi baru, silahkan \"QUIT\" terlebih dahulu **\n");
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
                if (Length(listCommand) == 2)
                {
                    char* savefile = toString(Get(listCommand, 1));
                    SAVE(savefile, listGame);
                }
                else
                {
                    printf("Mohon masukkan dengan format yang benar!\n");
                    printf("** Hint: Ketik \"HELP\" untuk melihat perintah **\n");
                }
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
            (loaded) ? DELETEGAME(&listGame, queueGame) : unknownCommand();
        }
        else if (compareWord(Get(listCommand, 0), "QUEUE") && compareWord(Get(listCommand, 1), "GAME"))
        {
            (loaded) ? QUEUEGAME(listGame, &queueGame) : unknownCommand();
        }
        else if (compareWord(Get(listCommand, 0), "PLAY") && compareWord(Get(listCommand, 1), "GAME"))
        {
            if (loaded)
            {
                displayQueue(queueGame);
                PLAYGAME(listGame, &queueGame);
            }
            else
            {
                unknownCommand();
            }
    
        }
        else if (compareWord(Get(listCommand, 0), "SKIP") && compareWord(Get(listCommand, 1), "GAME"))
        {
            if (loaded)
            {
                if (isNumber(Get(listCommand, 2)))
                {
                    int i = toInt(Get(listCommand, 2));
                    SKIPGAME(listGame, &queueGame, i);
                }
                else
                {
                    printf("Mohon masukkan dengan format yang benar!\n");
                    printf("** Hint: Ketik \"HELP\" untuk melihat perintah **\n");
                }
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

        delay(1000);

    } while (active);

    return 0;
}