#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "console.h"

boolean SAVE(Word filename, ArrayDin listgame, ArrayDin listhistory)
{
    int i;
    FILE* savefile;
    savefile = fopen(filename.TabWord, "w+");
    if (savefile == NULL)
    {
        printf("Error opening the file %s", filename.TabWord);
        return false;
    }
    for (i = 0; i < listgame.Neff; i++)
    {
        fprintf(savefile, "%s\n", listgame.A[i].TabWord);
    }
    for (i = 0; i < listhistory.Neff; i++)
    {
        fprintf(savefile, "%s\n", listhistory.A[i].TabWord);
    }

    fputc('.', savefile);
    fclose(savefile);

    printf("Your progress is saved successfully. ^^\n");

    return true;
}

// void QUIT(ArrayDin listgame, ArrayDin listhistory)
// {
//     boolean invalid_input;
//     char user_input[10];
//     printf("BMO: Do you wish to save your current progress?\n");
//     do
//     {
//         invalid_input = false;
//         printf("** Hint: Type 'Yes' to save; Type 'No' to discard **\n");
//         printf("You: ");
//         fgets(user_input, 10, stdin);
//         if (compareStr(user_input, "Yes"))
//         {
//             char filename[50];
//             printf("Save-File Name: ");
//             fgets(filename, 50, stdin);
            
//             Word filenameW = toWord(filename);
//             SAVE(filenameW, listgame, listhistory);
//         }
//         else if (compareStr(user_input, "No"))
//         {
//             printf("Your progress is discarded.\n");
//         }
//         else
//         {
//             invalid_input = true;
//             printf("BMO: Unrecognized input. Please use the correct format!\n");
//         }
//     } while (invalid_input);

//     printf("BMO: It's been a fun journey playing with You. ^^\n");   
//     printf("BMO: But I think i- it's be --en t- t-- too f-- unn\n");
//     printf("BMO: Battery low. Shutdown.");
// }

void LOAD(char * filename, ArrayDin *arraygame){
    int n = 0;
    int i,j;
    int length = 0;
    int count = 0;
    char huruf;
    ElType kata;
    char* path = "data/";
    char* fileloc = strConcat(path,filename);
    STARTWORDFILE(fileloc);
    if (!EndWord){
        n = KataInt(currentWord1);
        ADVWORDFILE();
    for(i=0;i<n;i++){
        kata = currentWord1;
        InsertLast(arraygame,kata);
        ADVWORDFILE();
        }
    }
    // }
    printf("Load file berhasil!\n");
}