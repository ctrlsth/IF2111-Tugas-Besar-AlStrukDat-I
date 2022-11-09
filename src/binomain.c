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
    Queue queueGame; CreateQueue(&queueGame);
    TabWord listGame; MakeTabWord(&listGame);
    TabWord listCommand; MakeTabWord(&listCommand);

    boolean active = true;
    boolean loaded = false;

    /* *** MAIN LOOP *** */
    do
    {
        printf("ENTER COMMAND: ");
        STARTCMD();

        while (!EndWord)
        {
            InsertLast(&listCommand, currentCommand);
            ADVCMD();
        }

        if (compareWord(Get(listCommand, 0), "START"))
        {
            // START();
            loaded = true;
        }
        else if (compareWord(Get(listCommand, 0), "LOAD"))
        {
            // LOAD();
            loaded = true;
        }
        else if (compareWord(Get(listCommand, 0), "HELP"))
        {
            HELP();
        }
        else if (compareWord(Get(listCommand, 0), "QUIT"))
        {
            QUIT(listGame);
            active = false;
        }
        else if (compareWord(Get(listCommand, 0), "CREATE") && compareWord(Get(listCommand, 1), "GAME"))
        {
            (loaded) ? CREATE() : unknownCommand();
        }
        else if (compareWord(Get(listCommand, 0), "SAVE"))
        {
            if (loaded) 
            {
                SAVE(Get(listCommand, 1), listGame);
            }
            else
            {
                unknownCommand();
            }
        }
        else if (compareWord(Get(listCommand, 0), "LIST") && compareWord(Get(listCommand, 1), "GAME"))
        {
            (loaded) ? LIST() : unknownCommand();
        }
        else if (compareWord(Get(listCommand, 0), "DELETE") && compareWord(Get(listCommand, 1), "GAME"))
        {
            (loaded) ? DELETE() : unknownCommand();
        }
        else if (compareWord(Get(listCommand, 0), "QUEUE") && compareWord(Get(listCommand, 1), "GAME"))
        {
            (loaded) ? QUEUE() : unknownCommand();
        }
        else if (compareWord(Get(listCommand, 0), "PLAY") && compareWord(Get(listCommand, 1), "GAME"))
        {
            (loaded) ? PLAY() : unknownCommand();
        }
        else if (compareWord(Get(listCommand, 0), "SKIPGAME"))
        {
            if (loaded)
            {
                SKIPGAME(Get(listCommand, 1));
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

        listCommand.Neff = 0;

    } while (active);

    return 0;
}