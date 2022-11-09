#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "console.h"

void delay_tenth_sec(int number_of_pertenth_seconds)
{
    int milli_seconds = 100 * number_of_pertenth_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

void printDelay(char *daString)
{
    for (int i = 0; i < strLength(daString); i++)
    {
        printf("%c", daString[i]);
        delay_tenth_sec(1);
    }
}

void SAVE(Word file, TabWord listGame)
{

    int i;
    FILE *savefile;
    char path[50] = "./data/";
    char *filename = toString(file);

    for (i = 7; i < strLength(filename) + 7; i++)
    {
        path[i] = filename[i - 7];
    }

    savefile = fopen(path, "w+");
    if (savefile == NULL)
    {
        printf("\n------------------------------\n");
        printf("Error opening the file %s\n", filename);
        printf("------------------------------\n\n");
    }
    else
    {
        char num[3];
        sprintf(num, "%d", listGame.Neff);
        fputs(num, savefile);
        fputs("\n", savefile);
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
                SAVE(currentCommand, listGame);
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
    delay_tenth_sec(20);
}