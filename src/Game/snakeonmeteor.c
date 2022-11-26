#include "snakeonmeteor.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArena(List matriks){
    int i,j;
    printf("Berikut merupakan peta permainan:\n");
    printf("x-----x-----x-----x-----x-----x\n");
    address row = matriks.zero;
    int baris = 0;
    int kolom = 0;
    while(baris < 5){
        printf("|");
        address col = row;
        while(kolom < 5){
            printf(" %s |", col->info);
            col = col->next_col;
            kolom +=1;
        }
        kolom = 0;
        printf("\n");
        printf("x-----x-----x-----x-----x-----x\n");
        row = row->next_row;
        baris +=1;
    }
    printf("\n");
}

void snakemeteor(){
    srand(time(0));
    char input;
    int n = 1;
    int turn = 1;
    int score;
    boolean endgame = false;
    boolean invalid_input;
    int baris = rand() % 5;
    int kolom = rand() % 5;
    List ular;
    create_linked_list_matrix(&ular,5,5, baris, kolom,&n);
    SummonFood(&ular);
    summonobstacle(&ular, 3);
    while(!endgame){
        printArena(ular);
        invalid_input = true;
        while(invalid_input && !endgame){
            printf("TURN %d\n",turn);
            printf("Silahkan masukkan command anda: ");
            STARTCMD(true);
            if (compareCharWord(currentCommand,'a') || compareCharWord(currentCommand,'s') || compareCharWord(currentCommand,'d') || compareCharWord(currentCommand,'w')){
                input = currentCommand.TabChar[0];
                if (isNabrakMeteor(ular,input)){
                    printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut. Silahkan masukkan command lainnya\n");
                }
                else{
                    MeteorDisappear(&ular);
                    if(isNabrak(ular,input)){
                        printf("Kepala Anda menabrak\n");
                        printf("Game over!\n");
                        endgame = true;
                    }
                    else{
                        system("cls");
                        movesnake(&ular,input,&n);
                        SummonFood(&ular);
                        SummonMeteor(&ular, &endgame,&n);
                        // printArena(ular);
                        invalid_input = false;
                    }
                }
            }
            else{
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
            }
        }
        turn +=1;
    }

    if (endgame){
        printArena(ular);
        score = n * 2;
        printf("Score Anda = %d\n",score);
    }
}

// int main(){
//     srand(time(0));
//     snakemeteor();
// }