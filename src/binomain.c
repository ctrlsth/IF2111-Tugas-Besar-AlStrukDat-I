#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/array.h"
#include "ADT/queue.h"
#include "boolean.h"
#include "console.h"

int main()
{
    /* Initialize */
    boolean prompt = true;
    boolean mainmenu = false;
    boolean recognizedCMD = true;
    Word currArg;
    Word currCommand;
    TabWord listgame;
    TabWord listhistory;

    /* Algorithm */
    // BOOTUP(); // Isinya welcome dsb ama enter command
    do
    {
        printf("ENTER COMMAND: ");
        STARTCMD();
        currCommand = GetCWord1();

        /* FIRST MENU / BOOT MENU */
        if (compareWord(currCommand, "START"))
        {
            // mainmenu = START("./data/config.txt");       // START jadi fungsi yang mengembalikan true, kalo file config bisa dibuka
        }
        else if (compareWord(currCommand, "LOAD"))
        {
            currArg = addtxt(GetCWord2());
            // mainmenu = LOAD(currArg);             // LOAD jadi fungsi yang ngembaliin true, kalo file save bisa dibuka
        }
        else if (compareWord(currCommand, "CMDLIST"))
        {
            // CMDLIST();                            // Ngeprint command list untuk main menu / interface awal
        }
        else if (compareWord(currCommand, "EXIT"))
        {
            // EXIT();
        }
        else
        {
            if (!mainmenu)
            {
                recognizedCMD = false;
            }
        }

        if (mainmenu)
        {
            if (compareWord(currCommand, "SAVE"))
            {
                currArg = addtxt(GetCWord2());
                SAVE(currArg, listgame, listhistory);
            }
            else
            {
                recognizedCMD = false;
            }
        }

        if (!recognizedCMD)
        {
            printf("BMO doesn't get what you say, but BMO hopes that you have a GREAT DAY!\n");
            printf("In any case that you're confused, just say \"CMDLIST\" okayy? ^^\n");
            recognizedCMD = true;
        }

    } while (prompt);

    return 0;
}