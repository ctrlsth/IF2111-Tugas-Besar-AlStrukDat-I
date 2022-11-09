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
    ArrayDin listgame;
    ArrayDin Command;
    MakeArrayDin(&Command);
    MakeArrayDin(&listgame);
    Queue qgame;
    CreateQueue(&qgame);
    ArrayDin listhistory;
    MakeArrayDin(&listhistory);
    int i,j;

    while(!(mainmenu) && (prompt)){
        printf("ENTER COMMAND: ");
        CMD_STARTKATA();
        while(!EndWord){
            // for(i=0;i<currCom.length;i++){
            //     printf("%c",currCom.buffer[i]);
            // }
            InsertLast(&Command,currentWord1);
            CMD_ADVKATA();
        }
        if (compareWord(Command.A[0], "START"))
        {
            LOAD("config.txt",&listgame);
            mainmenu = true;
            // mainmenu = START("./data/config.txt");       // START jadi fungsi yang mengembalikan true, kalo file config bisa dibuka
        }
        else if (compareWord(Command.A[0], "LOAD"))
        {
            // CMD_ADVKATA();
            // currArg = currentWord1;
            char *filename = toString(Command.A[1]);
            printf("%s",filename);
            // LOAD(filename,&listgame);
            mainmenu = true;
        }

        else if (compareWord(currCommand,"EXIT")){
            prompt = false;
            printf("SAMPAI JUMPA!");
    }
    }

    while(prompt){
        printf("ENTER COMMAND: ");
        STARTCMD();
        currCommand = GetCWord1();
        if(compareWord(currCommand, "LIST")){
            currArg = GetCWord2();
            if (compareWord(currArg,"GAME")){
                printf("list game anda:\n");
                for (i=0;i<listgame.Neff;i++){
                        printf("%d. ",i + 1);
                        for(j=0;j<listgame.A[i].Length;j++){
                            printf("%c",listgame.A[i].TabWord[j]);
                        }
                        printf("\n");
                    }
            }
        }

        else if (compareWord(currCommand,"EXIT")){
            prompt = false;
            printf("SAMPAI JUMPA!");
        }
    }
    /* Algorithm */
    // BOOTUP(); // Isinya welcome dsb ama enter command
    

    return 0;
}