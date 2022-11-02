#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/array.h"
#include "ADT/queue.h"
#include "boolean.h"

char* readTXTinput (char* command)
{
    char filename[50];
    int i = 0, j = 0;
    boolean passedSpace = false;
    while (i < strLength(command))
    {
        if (command[i] == ' ')
        {
            passedSpace = true;
        }
        if (passedSpace)
        {
            filename[j] = command[i];
            j++;
        }
    }

    return filename;
}

int main()
{
    char user_input[100];
    char filename[50];
    Word inputW;
    boolean bootloop = true, mainloop = true;
    printf("Who wants to play video games?\n");
    // BOOTCMD(); // { Print Command yang bisa dijalankan: START, LOAD namafile.txt, QUIT }
    do
    {
        printf("ENTER COMMAND: ");
        fgets(user_input, 100, stdin);
        inputW = toWord(user_input);

        if (cmpWordStr(user_input, "START"))
        {
            // START(filename);
            bootloop = false;
        }
        else if (cmpWordStr(user_input, "LOAD"))
        {            
            // LOAD(readTXTinput(user_input));
            bootloop = false;
        }
        else if (cmpWordStr(user_input, "EXIT"))
        {
            // EXIT();
            bootloop = false;
            mainloop = false;
        }
        else if (cmpWordStr(user_input, "CMDLIST"))
        {
            // BOOTCMD();
        }
        else
        {
            printf("BMO doesn't get what you say.. but BMO hopes you have a Great Day! ^^\n");
            printf("Oh, and if you need some guide, just give me a 'CMDLIST' ^^\n");
        }
    } while (bootloop);

    while (mainloop)
    {
        printf("ENTER COMMAND: ");
        fgets(user_input, 100, stdin);
        

    }

    return 0;
}