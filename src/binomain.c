#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/array.h"
#include "ADT/queue.h"
#include "boolean.h"

int main()
{
    boolean prompt = true;
    boolean bootloop = true;
    boolean mainloop = false;
    Word currArg;
    Word currCommand;
    BOOTUP(); // Isinya welcome dsb ama enter command
    do
    {
        printf("ENTER COMMAND: ");
        STARTWORD(prompt);
        currCommand = GetCWord();

        if (compareWord(currCommand, "START"))
        {
            // mainloop = START("config.txt");       // START jadi fungsi yang mengembalikan true, kalo file config bisa dibuka
            bootloop = false;                        // ataupun false, kalo file config gabisa dibuka (NULL).
        }
        else if (compareWord(currCommand, "LOAD"))
        {
            currArg = addtxt(GetCWord2());
            // mainloop = LOAD(currArg);             // LOAD jadi fungsi yang ngembaliin true, kalo file save bisa dibuka
            bootloop = false;                        // ataupun false, kalo file save gabisa dibuka (NULL).
        }
        else if (compareWord(currCommand, "CMDLIST"))
        {
            // CMDLIST();                            // Ngeprint command list untuk main menu / interface awal
        }
        else if (compareWord(currCommand, "EXIT"))
        {
            // EXIT();
            bootloop = false;
        }
        else
        {
            printf("BMO doesn't get what you say, but BMO hopes that you have a GREAT DAY!");
            printf("In any case that you're confused, just say \"CMDLIST\" okayy? ^^");
        }
    } while (bootloop);

    return 0;
}