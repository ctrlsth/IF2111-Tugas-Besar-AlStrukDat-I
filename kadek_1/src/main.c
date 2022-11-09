#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
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

    while (!(mainmenu) && prompt){  //Selama program masih berjalan dan belum memasuki mainmenu
        MakeArrayDin(&Command);     //Membuat Command kosong
        printf("Masukkan Command:");
        STARTKATA();
        while(!EndKata){            // memasukkan command kedalam array of kata
            currCom = CKata;
            InsertLast(&Command,currCom);
            ADVKATA();
        }
        if (Command.Neff > 2){      // input command lebih dari 2 kata dianggap tidak valid
            recognizedCMD = false;
        }

        else if (COMMAND_START_LOAD_ETC(mainmenu,Command)){
            printf("Anda harus melakukan start atau load untuk melakukan command tersebut!\n");
        }

        else if (Command.Neff == 1){ //User menginput command sebanyak 1 kata
            if (compareWord(Command.A[0],"START")){
                start("data/config.txt",&listgame,&fileopen);
                if (fileopen){ //startfile berhasil
                    mainmenu = true;
                }
            }
            else if(compareWord(Command.A[0], "HELP")){
                help(mainmenu);
            }
            else if (compareWord(Command.A[0], "QUIT")){
                prompt = false; //Keluar dari program
            }
            else{
                recognizedCMD = false;
            }
        }
        else if (Command.Neff == 2){
            if (compareWord(Command.A[0], "LOAD")){
                char *filename = toString(Command.A[1]);
                LOAD(filename,&listgame,&fileopen);
                if (fileopen){
                    mainmenu = true;
                }
            }
        
            else{
                recognizedCMD = false;
            }
        }

        if (!recognizedCMD){    //input tidak valid
            printf("BMO doesn't get what you say, but BMO hopes that you have a GREAT DAY!\n");
            printf("In any case that you're confused, just say \"CMDLIST\" okayy? ^^\n");
            recognizedCMD = true;
        }
        DeallocateArrayDin(&Command); //Dealokasi array command
    }


    while(prompt){
        MakeArrayDin(&Command);
        printf("Masukkan Command:");
        STARTKATA();
        while(!EndKata){
            currCom = CKata;
            InsertLast(&Command,currCom);
            ADVKATA();
        }

        if (Command.Neff > 2){
            recognizedCMD = false;
        }

        else if (COMMAND_START_LOAD_ETC(mainmenu,Command)){
            printf("Anda sudah melakukan START atau LOAD!\n");
        }
        

        else if (Command.Neff == 2){
            if(compareWord(Command.A[0],"LIST") && (compareWord(Command.A[1],"GAME"))){
                    printf("list game anda:\n");
                    for (i=0;i<listgame.Neff;i++){
                        printf("%d. ",i + 1);
                        for(j=0;j<listgame.A[i].Length;j++){
                            printf("%c",listgame.A[i].TabKata[j]);
                        }
                            printf("\n");
                        }
            }

            else if(compareWord(Command.A[0],"CREATE") && (compareWord(Command.A[1],"GAME"))){
                printf("Masukkan nama game yang akan ditambahkan: ");
                STARTKATAGAME();
                InsertLast(&listgame,CKata);
                printf("Game berhasil ditambahkan");
            }

            else if(compareWord(Command.A[0],"QUEUE") && (compareWord(Command.A[1],"GAME"))){
                QUEUEGAME(listgame,&queuegame);
            }

            else{
                recognizedCMD = false;
            }
            // else if ()
        }

        else if (Command.Neff == 1){
            if (compareWord(Command.A[0],"QUIT")){
                prompt = false;
            }

            else{
                recognizedCMD = true;
            }
        }
        // if (compareWord(Command.A[0],"START")){
        //     printf("Anda sudah melakukan START / LOAD\n");
        // }

        if (!recognizedCMD){
            printf("BMO doesn't get what you say, but BMO hopes that you have a GREAT DAY!\n");
            printf("In any case that you're confused, just say \"CMDLIST\" okayy? ^^\n");
            recognizedCMD = true;
        }
        DeallocateArrayDin(&Command);
    }
    return 0;
}