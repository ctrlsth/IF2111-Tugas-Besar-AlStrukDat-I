#include "snakeonmeteor.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void snakeart(){
    printf(" _______  _        _______  _        _______    _        _______ ");printf("       ---_ ......._-_--. \n");
    printf("(  ____ \\| \\    /\\(  ___  )( (    /|(  ____ \\  ( (    /|(  ___  )");printf("      (|\\ /      / /| \\  \\   \n");
    printf("| (    \\/|  \\  / /| (   ) ||  \\  ( || (    \\/  |  \\  ( || (   ) |");printf("      /  /     .'  -=-'   `. \n");
    printf("| (__    |  (_/ / | (___) ||   \\ | || (_____   |   \\ | || |   | |");printf("     /  /    .'             )\n");
    printf("|  __)   |   _ (  |  ___  || (\\ \\) |(_____  )  | (\\ \\) || |   | |");printf("   _/  /   .'        _.)   / \n");
    printf("| (      |  ( \\ \\ | (   ) || | \\   |      ) |  | | \\   || |   | |");printf("  / o   o        _.-' /  .'  \n");
    printf("| (____/\\|  /  \\ \\| )   ( || )  \\  |/\\____) |  | )  \\  || (___) |");printf("  \\          _.-'    / .'*|  \n");
    printf("(_______/|_/    \\/|/     \\||/    )_)\\_______)  |/    )_)(_______)");printf("   \\______.-'//    .'.' \\*|  \n");
    printf("      _______  _______ _________ _______  _______  _______       "); printf("    \\|  \\ | //   .'.' _ |*|  \n");
    printf("     (       )(  ____ \\\\__   __/(  ____ \\(  ___  )(  ____ )      ");printf("     `   \\|//  .'.'_ _ _|*|  \n");
    printf("     | () () || (    \\/   ) (   | (    \\/| (   ) || (    )|      ");printf("      .  .// .'.' | _ _ \\*|  \n");
    printf("     | || || || (__       | |   | (__    | |   | || (____)|      ");printf("      \\`-|\\_/ /    \\ _ _ \\*\\ \n");
    printf("     | |(_)| ||  __)      | |   |  __)   | |   | ||     __)      ");printf("       `/'\\__/      \\ _ _ \\*\\ \n");
    printf("     | |   | || (         | |   | (      | |   | || (\\ (         ");printf("      /^|            \\ _ _ \\*  \n");
    printf("     | )   ( || (____/\\   | |   | (____/\\| (___) || ) \\ \\__      ");printf("     '  `             \\ _ _ \\  \n");     
    printf("     |/     \\|(_______/   )_(   (_______/(_______)|/   \\__/      ");printf("                       \\_      \n");
    // delay(2000);
    printf("\n\n\n");

    printf("TEKAN ENTER UNTUK MEMULAI PERMAINAN...");
    STARTCMD(true);
}

void setGameSnake(List *head, int* count_row, int*count_cols, int *n){
    int n_obstacle;
    boolean invalid_input = true;
    while(invalid_input){
        printf("Masukan panjang arena yang ingin anda mainkan (Minimal 5): ");
        STARTCMD(true);
        if(isNumber(currentCommand)){
            if((toInt(currentCommand) >= 5)){
                *count_row = toInt(currentCommand);
                *count_cols = toInt(currentCommand);
                printf("Masukan banyak obstacle yang ingin anda mainkan :");
                STARTCMD(true);
                if(isNumber(currentCommand)){
                    if(((*count_cols) * (*count_row)) - 3 - toInt(currentCommand) > 0){
                        n_obstacle = toInt(currentCommand);
                        invalid_input = false;
                    }
                    else{
                        printf("Input tidak valid ! Jumlah obstacle melebihi luas arena dan panjang snake awal\n");
                    }
                }
                else{
                    printf("Input tidak valid! Masukan harus berupa angka! \n");
                }
            }
            else{
                printf("Input tidak valid! Panjang arena minimal adalah 5\n");
            }
        }
        else{
            printf("Input tidak valid! Masukan harus berupa angka! \n");
        }
    }
    int baris = rand() % (*count_row);
    int kolom = rand() % (*count_cols);
    create_linked_list_matrix(head,*count_row,*count_cols, baris, kolom);
    createsnake(head,baris,kolom,n);
    SummonFood(head,*count_row,*count_cols);
    summonobstacle(head,n_obstacle,*count_row,*count_cols);
}

void printArena(List matriks, int n_row, int n_cols){
    int i,j;
    printf("Berikut merupakan peta permainan:\n");
    for(i=0;i<n_cols;i++){
        if(i != n_cols - 1){
            printf("x-----");    
        }
        else{
            printf("x-----x\n");    
        }    
    }
    // printf("x-----x-----x-----x-----x-----x\n");
    addressNode row = matriks.zero;
    int baris = 0;
    int kolom = 0;
    while(baris < n_row){
        printf("|");
        addressNode col = row;
        while(kolom < n_cols){
            printf(" %s |", col->info);
            col = col->next_col;
            kolom +=1;
        }
        kolom = 0;
        printf("\n");
        for(i=0;i<n_cols;i++){
            if(i != n_cols - 1){
                printf("x-----");    
            }
            else{
                printf("x-----x\n");    
            }    
        }
        // printf("x-----x-----x-----x-----x-----x\n");
        row = row->next_row;
        baris +=1;
    }
    printf("\n");
}


void snakeonmeteor(int *score){
    srand(time(0));
    char input;
    int n = 1;
    int turn = 1;
    boolean endgame = false;
    boolean invalid_input;
    int n_baris;
    int n_kolom;
    List ular;
    snakeart();
    clear();
    setGameSnake(&ular,&n_baris,&n_kolom,&n);
    while(!endgame){
        printArena(ular,n_baris,n_kolom);
        invalid_input = true;
        if(!isNotMoveable(ular)){
            while(invalid_input && !endgame){
                printf("TURN %d\n",turn);
                printf("Silahkan masukkan command anda: ");
                STARTCMD(true);
                if (compareCharWord(currentCommand,'a') || compareCharWord(currentCommand,'s') || compareCharWord(currentCommand,'d') || compareCharWord(currentCommand,'w')){
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
                                clear();
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
        printArena(ular,n_baris,n_kolom);
        *score = n * 2;
        printf("Score Anda = %d\n",*score);
    }
}

// int main(){
//     srand(time(0));
//     int score;
//     // List ular;
//     // int n = 1;
//     // int baris = rand() % 5;
//     // int kolom = rand() % 5;
//     // create_linked_list_matrix(&ular,5,5, baris, kolom,&n);
//     // SummonFood(&ular);
//     // summonobstacle(&ular, 3);
//     // printf("Berikut adalah permainan ular\n");
//     // printArena(ular);
//     // List copyular = ular;
//     // printf("Berikut adalah permainan copyluar\n");
//     // printArena(copyular);
//     snakeonmeteor(&score);
// }