#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void unknownCommand()
{
    printf("BMO: Perintah tidak dikenali! Tolong masukan perintah yang valid!\n");
    printf("** Hint: Ketik \"HELP\" untuk melihat perintah **\n");
}

int main()
{
    system("cls");
    int i,j;
    ArrayDin listgame;              //berisi kumpulan game yang dimiliki oleh user
    ArrayDin Command;               // berisi command yang diinput oleh user
    ElType currCom;
    Queue queuegame;
    CreateQueue(&queuegame);
    MakeArrayDin(&listgame);        //Membuat listgame kosong
    boolean fileopen = false;       //Memeriksa apakah file berhasil dibuka
    boolean prompt = true;          //Memeriksa apakah program masih berjalan
    boolean mainmenu = false;       //Memeriksa apakah program sudah memasuki mainmenu
    boolean recognizedCMD = true;   //Memeriksa apakah input user valid

    //Selama program masih berjalan
    while (prompt)
    { 
        MakeArrayDin(&Command);     //Membuat Command kosong
        printf("\nMasukkan Command:");
        STARTKATA();
        system("cls");
        printDelay("BMO: Mengenali perintah",20);
        printDelay("...\n", 200);
        system("cls");        
        while(!EndKata)
        //memasukkan command kedalam array of kata             
        {           
            currCom = CKata;
            InsertLast(&Command,currCom);
            ADVKATA();
        }
        if (!mainmenu)
        // program belum memasuki mainmenu
        {
            if (Command.Neff > 2)
            // input command lebih dari 2 kata dianggap tidak valid
            {      
                recognizedCMD = false;
            }

            else if (COMMAND_START_LOAD_ETC(mainmenu,Command))
            //Ingin melakukan command LIST GAME, CREATE GAME, dsb tapi belum melakukan START atau LOAD
            {
                printf("Anda harus melakukan start atau load untuk melakukan command ");
                for(i=0;i<Command.Neff;i++){
                    printKata(Command.A[i]);
                    printf(" ");
                }
                printf("\n");
            }

            else if (Command.Neff == 1)
            //User menginput command sebanyak 1 kata
            {    
                if (compareWord(Command.A[0],"START"))
                {
                    start("data/config.txt",&listgame,&fileopen);
                    if (fileopen)
                    //startfile berhasil
                    {
                        mainmenu = true;
                    }
                }
                else if(compareWord(Command.A[0], "HELP"))
                {
                    help(mainmenu);
                }
                else if (compareWord(Command.A[0], "QUIT"))
                {
                    QUIT(listgame);
                    prompt = false; //Keluar dari program
                }
                else
                {
                    recognizedCMD = false;
                }
            }
            else if (Command.Neff == 2)
            //user menginput command sebanyak 2 kata
            {
                if (compareWord(Command.A[0], "LOAD"))
                {
                    char *filename = toString(Command.A[1]);
                    LOAD(filename,&listgame,&fileopen);
                    if (fileopen)
                    {
                        mainmenu = true;
                    }
                }
        
                else
                {
                    recognizedCMD = false;
                }
            }

        }

        else
        {
            if (Command.Neff > 2)
            // input command lebih dari 2 kata dianggap tidak valid
            {
                recognizedCMD = false;
            }

            else if (COMMAND_START_LOAD_ETC(mainmenu,Command))
            {
                printf("Anda sudah melakukan START atau LOAD!\n");
                printf("Masukan command \"QUIT\" jika ingin load file yang lain\n");
            }
        

            else if (Command.Neff == 2)
            //user menginput command sebanyak 2 kata
            {
                if(compareWord(Command.A[0],"LIST") && (compareWord(Command.A[1],"GAME")))
                {
                    LISTGAME(listgame);
                }

                else if(compareWord(Command.A[0],"CREATE") && (compareWord(Command.A[1],"GAME")))
                {
                    CREATEGAME(&listgame);
                }

                else if(compareWord(Command.A[0],"QUEUE") && (compareWord(Command.A[1],"GAME")))
                {
                    QUEUEGAME(listgame,&queuegame);
                }

                else if (compareWord(Command.A[0],"PLAY") && (compareWord(Command.A[1],"GAME")))
                {
                    PLAYGAME(&queuegame);
                }

                else if(compareWord(Command.A[0],"SKIPGAME"))
                {
                    if(IsNumber(Command.A[1]))
                    {
                        int number = KataInt(Command.A[1]);
                        SKIPGAME(&queuegame,number);
                    }
                    else
                    {
                        printf("Input tidak valid!\n");
                    }
                }

                else if (compareWord(Command.A[0],"DELETE") && (compareWord(Command.A[1],"GAME")))
                {
                    DELETEGAME(&listgame,queuegame);
                }

                else if (compareWord(Command.A[0],"SAVE")){
                    // char *filesave = toString(Command.A[1]);
                    SAVE(Command.A[1],listgame);

                }

                else
                {
                    recognizedCMD = false;
                }
            }

            else if (Command.Neff == 1)
            //user menginput command sebanyak 1 kata
            {
                if (compareWord(Command.A[0],"QUIT"))
                {
                    QUIT(listgame);
                    prompt = false;
                }
                else if (compareWord(Command.A[0],"HELP"))
                {
                    help(mainmenu);
                }
                else
                {
                    recognizedCMD = false;
                }
            }
        }
        

        if (!recognizedCMD)
        //input tidak valid
        {
            unknownCommand();
            recognizedCMD = true;
        }
        DeallocateArrayDin(&Command); //Dealokasi array command
    }
    return 0;
}