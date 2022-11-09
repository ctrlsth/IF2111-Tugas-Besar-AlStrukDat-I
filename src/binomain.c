#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/array.h"
#include "ADT/queue.h"
#include "boolean.h"
#include "console.h"

void unknownCommand()
{
    printf("BMO doesn't get what you say, but BMO hopes that you have a GREAT DAY!\n");
    printf("In any case that you're confused, just say if you need \"HELP\" okayy? ^^\n");
}

int main()
{
    /* *** INISIALISASI *** */
    Queue queueGame;
    CreateQueue(&queueGame);
    TabWord listGame;
    MakeEmpty(&listGame);

    boolean active = true;
    boolean loaded = false;

    /* *** MAIN LOOP *** */
    do
    {
        printf("ENTER COMMAND: ");
        STARTCMD();
        if (compareWord(currentCommand, "START"))
        {
            // START();
            loaded = true;
        }
        else if (compareWord(currentCommand, "LOAD"))
        {
            // LOAD();
            loaded = true;
        }
        else if (compareWord(currentCommand, "HELP"))
        {
            HELP();
        }
        else if (compareWord(currentCommand, "EXIT"))
        {
            EXIT();
            active = false;
        }
        else if (compareWord(currentCommand, "CREATE"))
        {
            (loaded) ? CREATE() : unknownCommand();
        }
        else if (compareWord(currentCommand, "LIST"))
        {
            (loaded) ? LIST() : unknownCommand();
        }
        else if (compareWord(currentCommand, "DELETE"))
        {
            (loaded) ? DELETE() : unknownCommand();
        }
        else if (compareWord(currentCommand, "QUEUE"))
        {
            (loaded) ? QUEUE() : unknownCommand();
        }
        else if (compareWord(currentCommand, "PLAY"))
        {
            (loaded) ? PLAY() : unknownCommand();
        }
        else if (compareWord(currentCommand, "SKIPGAME"))
        {
            (loaded) ? SKIPGAME() : unknownCommand();
        }
        else
        {
            unknownCommand();
        }

    } while (active);

    return 0;
}