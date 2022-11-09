#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "console.h"

void SAVE(Word file, TabWord listGame)
{

    int i;
    FILE *savefile;
    char path[50] = "./data/";
    char *filename = toString(file);

    for (i = 7; i < strLength(filename) + 7; i++)
    {
        path[i] = filename[i-7];
    }

    savefile = fopen(path, "w+");
    if (savefile == NULL)
    {
        printf("\n----------------------------\n");
        printf("Error opening the file %s\n", filename);
        printf("----------------------------\n\n");
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
        printf("BMO: Do you wish to save your current progress?\n");
        do
        {
            invalid_input = false;
            printf("** Hint: Type 'Yes' to save; Type 'No' to discard **\n");
            printf("You: ");
            STARTCMD();
            if (compareWord(currentCommand, "Yes"))
            {
                printf("\nBMO: Please name your save file!\n");
                printf("File Name: ");
                STARTCMD();
                SAVE(currentCommand, listGame);
            }
            else if (compareWord(currentCommand, "No"))
            {
                printf("\nBMO: Your progress is discarded.\n");
            }
            else
            {
                invalid_input = true;
                printf("BMO: Unrecognized input. Please use the correct format!\n");
            }

        } while (invalid_input);
    }

    printf("BMO: It's been a fun journey playing with You. ^^\n");
    printf("BMO: But I think i- it's be --en t- t-- too f-- unn\n");
    printf("BMO: Battery low. Shutdown.\n");
}