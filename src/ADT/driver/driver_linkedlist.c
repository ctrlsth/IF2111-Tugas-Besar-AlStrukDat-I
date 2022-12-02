#include "../linkedlist.h"
#include <time.h>
#include <stdlib.h>

int main(){
    /*CERITANYA BLINDED SNAKE ON METEOR*/
    printf("CERITANYA BLINDED SNAKE ON METEOR\n");
    srand(time(0));
    char input;
    int score;
    int n = 1;
    int turn = 1;
    boolean endgame = false;
    boolean invalid_input;
    int n_baris = 5;
    int n_kolom = 5;
    int baris = rand() % n_baris;
    int kolom = rand() % n_kolom; 
    List ular;

    // snakeart();
    //clear();
    // GameSetSnake(&ular,&n_baris,&n_kolom,&n);
    create_linked_list_matrix(&ular,n_baris,n_kolom, baris, kolom);
    createsnake(&ular,baris,kolom,&n);
    SummonFood(&ular,n_baris,n_kolom);
    summonobstacle(&ular, 3,n_baris,n_kolom);
    while(!endgame){
        // printArena(ular,n_baris,n_kolom);
        invalid_input = true;
        if(!isNotMoveable(ular)){
            while(invalid_input && !endgame){
                printf("TURN %d\n",turn);
                printf("Silahkan masukkan command anda: ");
                STARTCMD(true);
                UPPER(&currentCommand);
                if (compareCharWord(currentCommand,'A') || compareCharWord(currentCommand,'S') || compareCharWord(currentCommand,'D') || compareCharWord(currentCommand,'W')){
                    input = currentCommand.TabChar[0];
                    if(isNabrakBody(ular,input)){
                        printf("Kepala tidak dapat bergerak ke badan sendiri! silakan masukkan command lainnya\n");
                    }
                    else{
                        // printf("Gak nabrak\n");
                        if (isNabrakMeteor(ular,input)){
                            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut. Silahkan masukkan command lainnya\n");
                        }
                        else{
                            MeteorDisappear(&ular,n_baris,n_kolom);
                            if(isNabrak(ular,input)){
                                printf("Kepala Anda menabrak\n");
                                printf("Game over!\n");
                                endgame = true;
                            }
                            else{
                                //clear();
                                movesnake(&ular,input,&n);
                                SummonFood(&ular,n_baris,n_kolom);
                                SummonMeteor(&ular, &endgame,&n,n_baris,n_kolom);
                                invalid_input = false;
                            }
                        }
                    }
                }
                else{
                    printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
                }
            }
            turn +=1;
        }
        else{
            endgame = true;
            printf("Ular sudah tidak bisa bergerak!\n");
            printf("Game over!\n");
        }
    }

    if (endgame){
        // printArena(ular,n_baris,n_kolom);
        score = n * 2;
        printf("Score Anda = %d\n",score);
    }
}