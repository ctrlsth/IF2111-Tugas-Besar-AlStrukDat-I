#include "start.h"
#include "load.h"
#include <stdio.h>
#include <string.h>

int main(){
    int i,j;
    ArrayDin T;
    ArrayDin Command;
    ElType currCom;
    char filename[100];
    MakeArrayDin(&T);
    boolean ended = false;
    
    while(!ended){
        MakeArrayDin(&Command);
        printf("Masukkan Command:");
        STARTKATA();
        while(!EndKata){
            currCom = toEltype(CKata);
            // for(i=0;i<currCom.length;i++){
            //     printf("%c",currCom.buffer[i]);
            // }
            InsertLast(&Command,currCom);
            ADVKATA();
        }
            // for(i=0;i<Command.Neff;i++){
            //     for(j=0;j<Command.A[i].length;j++){
            //         printf("%c",Command.A[i].buffer[j]);
            //     }
            //     printf("\n");
            // }

            if (Command.Neff == 1){
                if(compareWord(Command.A[0],"START")){
                    start("config.txt",&T);
                    printf("start file berhasil!\n");
                }
                else if(compareWord(Command.A[0],"EXIT")){
                    printf("Sampai jumpa!\n");
                    ended = true;
                }
            }
            else if(Command.Neff == 2){
                if(compareWord(Command.A[0],"LIST") && compareWord(Command.A[1],"GAME")){
                    printf("list game anda:\n");
                    for (i=0;i<T.Neff;i++){
                        printf("%d. ",i + 1);
                        for(j=0;j<T.A[i].length;j++){
                            printf("%c",T.A[i].buffer[j]);
                        }
                        printf("\n");
                    }
                }

                else if(compareWord(Command.A[0], "LOAD")){
                    for(i=0;i<Command.A[1].length;i++){
                        filename[i] = Command.A[1].buffer[i];
                    }
                    filename[i] = '\0';
                    LOAD(filename,&T);
                    printf("Load berhasil\n");
                }
            }

            else{
                printf("KAMU NENYE ");
                for (i = 0;i<Command.Neff;i++){
                    for(j=0;j<Command.A[i].length;j++){
                        printf("%c",Command.A[i].buffer[j]);
                    }
                    printf(" ");
                }
                printf("\n");
            }
            DeallocateArrayDin(&Command);
        }
        DeallocateArrayDin(&T);
    return 0;
}