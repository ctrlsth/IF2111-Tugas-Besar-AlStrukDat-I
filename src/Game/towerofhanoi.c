#include <stdio.h>
#include <stdlib.h>
#include "towerofhanoi.h"


void towerArt(){
    
}

void CreateTower(Stack *S, int tumpukan){
    // int a = 0;
    // int tumpukan = 5;
    int wmax = (tumpukan * 2) - 1;
    Word piring;
    for(int i = tumpukan; i>0; i--){
        piring.Length = 0;
        int panjang = (2 * i) - 1;
        for(int j = 0; j < wmax; j++){
            if((j < (wmax - panjang)/ 2) || (j > (wmax - panjang)/2 + (panjang-1))){
                piring.TabChar[j] = ' '; 
            }
            else{
                piring.TabChar[j] = '*';
                piring.Length +=1;
            }
        }
        Push(S,piring);
    }
}

void printPiring(Stack S, int i, int tumpukan){
    int wmax = (tumpukan * 2) - 1;
    if (i>S.TOP){
        for(int j = 0;j < wmax; j++){
            if((j < (wmax - 1) / 2) || ( j > (wmax - 1)/2)){
                printf(" ");
            }
            else{
                printf("|");
            }
        }
    }
    else{
        for(int j=0;j<wmax; j++){
            printf("%c", S.T[i].TabChar[j]);
        }
    }
}

void printDasar(char a, int tumpukan, int panjang){
    int wmax = (tumpukan * 2) - 1;
    for(int j = 0; j < wmax; j++){
            if((j < (wmax - panjang)/ 2) || (j > (wmax - panjang)/2 + (panjang-1))){
                printf(" "); 
            }
            else{
                printf("%c", a);
            }
        }
}

void printStack(Stack S1, Stack S2, Stack S3, int tumpukan){
    for(int i = (tumpukan - 1); i>=0; i--){
        printPiring(S1,i,tumpukan);
        printf("     ");
        printPiring(S2,i,tumpukan);
        printf("     ");
        printPiring(S3,i,tumpukan);
        printf("     ");
        printf("\n");
    }
    printDasar('-',tumpukan,(2*(tumpukan - 1) - 1));
    printf("     ");
    printDasar('-',tumpukan,(2*(tumpukan - 1) - 1));
    printf("     ");
    printDasar('-',tumpukan,(2*(tumpukan - 1) - 1));
    printf("     \n");
    printDasar('A',tumpukan,1);
    printf("     ");
    printDasar('B',tumpukan,1);
    printf("     ");
    printDasar('C',tumpukan,1);
    printf("     \n\n");
}

boolean isTowerFull(Stack S, int tumpukan){
    return (S.TOP == tumpukan - 1);
}

boolean isStackMoveable(Stack S1, Stack S2,int tumpukan){
    /*S1 merupakan stack asal dan S2 merupakan stack tujuan*/
    boolean moveable = false;
    //Jika S1 Empty maka tidak dapat dipindah

    if(!IsStackEmpty(S1)){
        if(IsStackEmpty(S2)){
            moveable = true;
        }
        else if(!IsStackEmpty(S2) && !isTowerFull(S2,tumpukan)){
            if ((S1.T[S1.TOP].Length) < (S2.T[S2.TOP].Length)){
                moveable = true;
            }
        }
    }
    return moveable;
}

void MovePiringan(Stack* S1, Stack *S2,int tumpukan, char a, char b, boolean * piringan_moved){
    Word piringan;
    if(isStackMoveable(*S1,*S2,tumpukan)){
        Pop(S1,&piringan);
        Push(S2,piringan);
        printf("Memindahkan piringan dari %c ke %c\n\n", a, b);
        *piringan_moved = true;
    }
    else{
        if(IsStackEmpty(*S1)){
            printf("Tiang %c kosong, silahkan memilih tiang lain\n\n", a);
        }
        else if(isTowerFull(*S2,tumpukan)){
            printf("Tiang %c penuh, silahkan memilih tiang lain yang ingin ditempatkan piringan\n\n", a);
        }
        else if(S1->T[S1->TOP].Length > S2->T[S2->TOP].Length){
            printf("Piring gagal dipindahkan dari %c ke %c (Ukuran piringan harus lebih kecil dari piringan dibawahnya!)\n\n", a , b);
        }
        *piringan_moved = false;
    }
}

boolean isTowerFinished(Stack S3, int tumpukan){
    return (isTowerFull(S3,tumpukan));
}

int FinalScore(int turn, int tumpukan){
    int move = turn - 1;
    int score;
    if(move <= 31){
        score = tumpukan * 2;
    }
    else if(move > 31 && move <=49){
        score = (tumpukan - 1) * 2;
    }
    else if (move >=50 && move <70){
        if (tumpukan <= 1){
            score = 0;
        }
        else{
            score = (tumpukan - 2) * 2;
        }
    }
    else if (move >=70 && move <90){
        if (tumpukan <= 2){
            score = 0;
        }
        else{
            score = (tumpukan - 3) * 2;
        }
    }
    else if (move >=90 && move <100){
        if (tumpukan <= 3){
            score = 0;
        }
        else{
            score = (tumpukan - 4) * 2;
        }
    }
    else{
        if (tumpukan <= 4){
            score = 0;
        }
        else{
            score = (tumpukan - 5) * 2;
        }
    }
    return score;
}


void towerOfHanoi(int *score){
    // int score;
    int turn = 1; 
    int tumpukan;
    boolean invalid_input = true;
    boolean piringan_moved;
    while(invalid_input){
        printf("Masukkan jumlah piringan: ");
        STARTCMD(true);
        if(isNumber(currentCommand)){
            if(toInt(currentCommand) == 0){
                printf("Jumlah piringan harus lebih dari nol\n");
            }
            else{
                tumpukan = toInt(currentCommand);
                printf("Bermain dengan %d piringan\n", tumpukan);
                invalid_input = false;
            }
        }
        else{
            printf("Input tidak valid! \n");
            printf("Hint: Masukan harus berupa angka lebih dari nol\n");
        }
    }
    Stack Tower, Tower1, Tower2;
    CreateEmptyStack(&Tower);
    CreateEmptyStack(&Tower1);
    CreateEmptyStack(&Tower2);
    CreateTower(&Tower, tumpukan);

    while(!isTowerFinished(Tower2,tumpukan)){
        invalid_input = true;
        Word asal;
        Word tujuan;
        // printStack(Tower,Tower1,Tower2, tumpukan);
        while(!isTowerFinished(Tower2,tumpukan) && invalid_input){
            printStack(Tower,Tower1,Tower2, tumpukan);
            printf("Turn %d\n", turn);
            printf("TIANG ASAL: ");
            STARTCMD(true);
            asal = currentCommand;
            printf("TIANG TUJUAN: ");
            STARTCMD(true);
            tujuan = currentCommand;
            clear();
            if((tujuan.Length == 1) && (asal.Length == 1)){
                if((asal.TabChar[0] == 'A' || asal.TabChar[0] == 'B' || asal.TabChar[0] == 'C') && (tujuan.TabChar[0] == 'A' || tujuan.TabChar[0] == 'B' || tujuan.TabChar[0] == 'C')){
                    if(asal.TabChar[0] == tujuan.TabChar[0]){
                        printf("Input tidak valid, tiang awal dan tiang akhir harus berbeda!\n\n");
                    }
                    else{
                        invalid_input = false;
                    }
                }
                else{
                    printf("Input tidak valid, tiang tidak tersedia!(A/B/C)\n");
                    printf("Hint: Masukkan input berupa huruf kapital (A/B/C)\n\n");
                }
            }
            else{
                printf("Input tidak valid\n");
                printf("Hint : Masukkan input berupa huruf kapital (A/B/C)\n\n");
            }
        }
        if (asal.TabChar[0] == 'A'){
            if (tujuan.TabChar[0] == 'B'){
                MovePiringan(&Tower,&Tower1,tumpukan,asal.TabChar[0],tujuan.TabChar[0],&piringan_moved);
            }
            else if (tujuan.TabChar[0] == 'C'){
                MovePiringan(&Tower,&Tower2,tumpukan,asal.TabChar[0],tujuan.TabChar[0],&piringan_moved);
            }
        }
        else if(asal.TabChar[0] == 'B'){
            if (tujuan.TabChar[0] == 'A'){
                MovePiringan(&Tower1,&Tower,tumpukan,asal.TabChar[0],tujuan.TabChar[0],&piringan_moved);
            }
            else if (tujuan.TabChar[0] == 'C'){
                MovePiringan(&Tower1,&Tower2,tumpukan,asal.TabChar[0],tujuan.TabChar[0],&piringan_moved);
            }
        }

        else if(asal.TabChar[0] == 'C'){
            if (tujuan.TabChar[0] == 'A'){
                MovePiringan(&Tower2,&Tower,tumpukan,asal.TabChar[0],tujuan.TabChar[0],&piringan_moved);
            }
            else if (tujuan.TabChar[0] == 'B'){
                MovePiringan(&Tower2,&Tower1,tumpukan,asal.TabChar[0],tujuan.TabChar[0],&piringan_moved);
            }
        }
        if(piringan_moved){
            turn +=1;
        }
    }
    printStack(Tower,Tower1,Tower2, tumpukan);
    *score = FinalScore(turn,tumpukan);
    printf("Yey! Kamu berhasil selesai memainkan game Tower of Hanoi dengan berjalan sebanyak %d langkah! \n", turn - 1);
    printf("Nilai kamu : %d\n", *score);
}