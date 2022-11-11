#include "marvelsnap.h"
#include "../console.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MakeArrayCard(ArrayCard* arraycard){
    arraycard->Neff = 0;
}

void MakeArrayInt(ArrayInt* arrayint){
    int i;
    arrayint->Neff = 0;
    for (i=0;i<4;i++){
        arrayint->kekuatan[i] = 0;
    }
}

void InsertCardAt(ArrayCard* array, Card el, int i){
    int j;
    for (j=array->Neff-1; j>= i;j--){
        (*array).Hand[j+1] = (*array).Hand[j];
    }
    array->Hand[i] = el;
    array->Neff+=1;
}

void SetIntAt(ArrayInt *array, int el, int i){
    array->kekuatan[i] = el;
    array->Neff +=1;
}

void DeleteCardAt(ArrayCard *array, int i, Card *el){
    int j;
    *el = array->Hand[i];
    for (j = i; j < array->Neff - 1;j++){
        array->Hand[j]=array->Hand[j+1];
    }
    array->Neff -=1;
}

int CardEnergy(){
    //Generate energy kartu secara random
    int energy = (rand() % 6) + 1; //Energy Kartu dari 1 - 6
    return energy;
}

int CardPower(int cardEnergy){
    //Generate kekuatan kartu secara random berdasarkan energy kartu
    int power;
    power = (rand() % (cardEnergy + 1)) + cardEnergy;
    // Energy card 1 --> Power antara 1 - 2
    // Energy card 2 --> Power antara 2 - 4
    // Energy card 3 --> Power antara 3 - 6
    // Energy card 4 --> Power antara 4 - 8
    // Energy card 5 --> Power antara 5 - 10
    // Energy card 6 --> Power antara 6 - 12
    return power;
}

Card randomCard(){
    //Generate kartu secara random
    Card kartu;
    kartu.Energy = CardEnergy();
    kartu.Power = CardPower(kartu.Energy);
    return kartu;
}

void insertRandomCard(ArrayCard* array){
    //Memasukkan kartu random ke tangan pemain (array card)
    Card kartu = randomCard();
    InsertCardAt(array,kartu,array->Neff);
}

void PrintArena(ArrayInt Arena1Player1, ArrayInt Arena2Player1, ArrayInt Arena3Player1,ArrayInt Arena1Player2, ArrayInt Arena2Player2, ArrayInt Arena3Player2){
    //Print arena yang sedang berlangsung
    int PowerArena1Player1 = Arena1Player1.kekuatan[0] + Arena1Player1.kekuatan[1]+ Arena1Player1.kekuatan[2]+ Arena1Player1.kekuatan[3];
    int PowerArena2Player1 = Arena2Player1.kekuatan[0] + Arena2Player1.kekuatan[1]+ Arena2Player1.kekuatan[2]+ Arena2Player1.kekuatan[3];
    int PowerArena3Player1 = Arena3Player1.kekuatan[0] + Arena3Player1.kekuatan[1]+ Arena3Player1.kekuatan[2]+ Arena3Player1.kekuatan[3];
    int PowerArena1Player2 = Arena1Player2.kekuatan[0] + Arena1Player2.kekuatan[1]+ Arena1Player2.kekuatan[2]+ Arena1Player2.kekuatan[3];
    int PowerArena2Player2 = Arena2Player2.kekuatan[0] + Arena2Player2.kekuatan[1]+ Arena2Player2.kekuatan[2]+ Arena2Player2.kekuatan[3];
    int PowerArena3Player2 = Arena3Player2.kekuatan[0] + Arena3Player2.kekuatan[1]+ Arena3Player2.kekuatan[2]+ Arena3Player2.kekuatan[3]; 
    printf("                PLAYER 1                \n");
    printf("                                      \n");
    printf("  %d     %d       %d     %d       %d     %d  \n",Arena1Player1.kekuatan[2],Arena1Player1.kekuatan[3],Arena2Player1.kekuatan[2],Arena2Player1.kekuatan[3],Arena3Player1.kekuatan[2],Arena3Player1.kekuatan[3]);
    printf("  %d     %d       %d     %d       %d     %d  \n",Arena1Player1.kekuatan[0],Arena1Player1.kekuatan[1],Arena2Player1.kekuatan[0],Arena2Player1.kekuatan[1],Arena3Player1.kekuatan[0],Arena3Player1.kekuatan[1]);
    printf("----[%d]-----  ----[%d]-----  ----[%d]----- \n",PowerArena1Player1,PowerArena2Player1,PowerArena3Player1);
    printf(":          :  :          :  :          : \n");
    printf(":  ARENA1  :  :  ARENA2  :  :  ARENA3  : \n");
    printf(":          :  :          :  :          : \n");
    printf("----[%d]-----  ----[%d]-----  ----[%d]----- \n",PowerArena1Player2,PowerArena2Player2,PowerArena3Player2);
    printf("  %d     %d       %d     %d       %d     %d  \n",Arena1Player2.kekuatan[0],Arena1Player2.kekuatan[1],Arena2Player2.kekuatan[0],Arena2Player2.kekuatan[1],Arena3Player2.kekuatan[0],Arena3Player2.kekuatan[1]);
    printf("  %d     %d       %d     %d       %d     %d  \n",Arena1Player2.kekuatan[2],Arena1Player2.kekuatan[3],Arena2Player2.kekuatan[2],Arena2Player2.kekuatan[3],Arena3Player2.kekuatan[2],Arena3Player2.kekuatan[3]);
    printf("                                      \n");
    printf("                PLAYER 2                \n");
    printf("\n");
}

void PrintCard(ArrayCard Player){
    //Print kartu yang dimiliki player
    int i;
    printf("Daftar Kartu :\n");
    printf("No | Power | Energy Cost \n");
    printf("-------------------------\n");
    for(i=0;i<Player.Neff;i++){
    printf("%d  |  %d    |      %d     \n",(i+1),Player.Hand[i].Power,Player.Hand[i].Energy);    
    }
}

void PlayerTurn(int* Energyturn, boolean* pemainNow, boolean* pemainThen, ArrayCard *Player, ArrayInt* Arena1Player, ArrayInt* Arena2Player, ArrayInt* Arena3Player){
    int n,m;
    Card kartu;
    boolean kartu_valid = false;
    boolean arena_valid = false;
    boolean valid = false;
    boolean skip = false;
    boolean turn_end = false;
    PrintCard(*Player);

    while(!kartu_valid){
        //Player Memilih Kartu yang ingin dimainkan
        printf("Energy : %d\n", *Energyturn);
        printf("Masukan nomor kartu yang ingin dimainkan: ");
        STARTCMD(false);
        if(isNumber(currentCommand)){
            n = toInt(currentCommand);
            if(n>0 && n<= Player->Neff){
                if(Player->Hand[n-1].Energy <= *Energyturn){
                    kartu_valid = true;
                }
                else{
                    //Energi tidak cukup
                    //Input diulang sampai valid
                    printf("Energy Anda tidak cukup\n");
                }
            }
            else{
                //Input diulang sampai valid
                printf("nomor kartu %d tidak ditemukan, silahkan pilih kartu lain\n \n",n);
                }
        }
        else{
            if(compareWord(currentCommand,"SKIP")){
                //Langsung ke validasi input (yakin atau tidak)
                kartu_valid = true;
                arena_valid = true;
                skip = true;
            }
            else{
                //Input diulang sampai valid
                printf("Input tidak valid\n \n");
            }
        }
    }

    while(!arena_valid){
        //Player memilih arena yang ingin dimasukkan kartu
        printf("Masukan arena yang ingin dimasukkan kartu(1/2/3): ");
        STARTCMD(false);
        if(isNumber(currentCommand)){
            m = toInt(currentCommand);
            if(m>0 && m<=3){
                if(m==1){
                    //Player memilih arena 1
                    if(Arena1Player->Neff < 4){
                        arena_valid = true;
                    }
                    else{
                        //Player memilih arena yang penuh
                        //input diulang sampai valid
                        printf("Arena %d penuh, silahkan pilih arena lain!\n \n",m);
                    }
                }
                if(m==2){
                    //Player memilih arena 2
                    if(Arena2Player->Neff < 4){
                        arena_valid = true;
                    }
                    else{
                        //Player memilih arena yang penuh
                        //input diulang sampai valid
                        printf("Arena %d penuh, silahkan pilih arena lain!\n \n",m);
                    }
                }
                if(m==3){
                    //Player memilih arena 3
                    if(Arena3Player->Neff < 4){
                        arena_valid = true;
                    }
                    else{
                        //Player memilih arena yang penuh
                        //input diulang sampai valid
                        printf("Arena %d penuh, silahkan pilih arena lain!\n \n",m);
                    }
                }
            }
            else{
                //Player memilih arena selain arena yang valid
                //input diulang sampai valid
                printf("nomor arena %d tidak ditemukan, silahkan pilih arena lain\n \n",m);
            }
        }
        else{
            //input diulang sampai valid
            printf("Input tidak valid\n \n");
        }
    }
    
    
    while(!valid){
        //Validasi input (apakah yakin atau tidak)
        printf("Apakah Anda yakin?(YES/NO) ");
        STARTCMD(false);
        if(compareWord(currentCommand, "YES")){
            //Ke bagian akhir
            valid = true;
            if(!skip){
                //Player tidak skip turn
                DeleteCardAt(Player,(n-1),&kartu);
                //Delete kartu yang dipilih lalu dimasukan ke arena
                *Energyturn -= kartu.Energy;
                //Energy berkurang sesuai cost kartu
                if (m==1){ //arena 1
                    //kartu masuk ke arena 1
                    SetIntAt(Arena1Player,kartu.Power,Arena1Player->Neff);
                }
                if (m==2){ //arena 2
                    //kartu masuk ke arena 2
                    SetIntAt(Arena2Player,kartu.Power,Arena2Player->Neff);
                }
                if (m==3){ //arena 3
                    //kartu masuk ke arena 3
                    SetIntAt(Arena3Player,kartu.Power,Arena3Player->Neff);
                }
            }
            else{
                //Player skip turn dan langsung berpindah pemain (turn berakhir)
                *pemainNow = false;
                *pemainThen = true;
                turn_end = true;
            }
        }
        else if(compareWord(currentCommand,"NO")){
            //turn berakhir namun tidak berpindah pemain (mengulang loop)
            valid = true;
            kartu_valid = false;
            arena_valid = false;
            turn_end = true;
        }
        else{
            //Input ulang sampai valid
            printf("Input tidak valid\n \n");
        }
    }

    while(!turn_end){
        //Player dapat mengulang turn kembali jika ingin memasukkan kartu lain dan energy masih sisa
        if (*Energyturn == 0){
            //Energy pemain habis maka langsung berpindah ke pemain selanjutnya
            *pemainNow = false;
            *pemainThen = true;
            turn_end = true;
        }
        else{
            printf("Sisa energy = %d\n",*Energyturn);
            printf("Apakah Anda masih ingin menaruh kartu? (YES/NO): ");
            STARTCMD(false);
            if(compareWord(currentCommand, "YES")){
                //Player mengulang turn kembali
                turn_end = true;
                arena_valid = false;
                kartu_valid = false;
                valid = false;
            }
            else if(compareWord(currentCommand,"NO")){
                //Player menyudahi turn
                *pemainNow = false;
                *pemainThen = true;
                turn_end = true;
            }
            else{
                //Mengulangi input sampai valid
                printf("Input tidak valid");
            }
        }
    }
}

void COMMANDGAME(){
    printf("GUIDE - ketik command ini untuk melihat cara dan aturan bermain\n");
    printf("PLAY - ketik command ini untuk memulai permainan\n");
    printf("Masukkan Command: ");
    STARTCMD(false);
}

void PLAYGUIDE(){
    printf("1.Game ini dimainkan dengan dua player dimana player 1 memulai turn terlebih dahulu\n");
    printf("2.Game ini dimainkan dalam enam turn dan pada masing turn, player mendapatkan energy sebesar jumlah turn\n");
    printf("3. Diawal Game setiap player mendapat tiga kartu dengan setiap player pasti mendapatkan kartu dengan cost 1, serta pada awal turn, setiap pemain mengambil 1 kartu random\n");
    printf("4.Terdapat tiga arena dimana pada masing - masing arena maksimal dimasukkan empat kartu untuk masing - masing player\n");
    printf("5.Pada setiap giliran, player dapat memasukkan kartu kedalam arena atau melakukan SKIP\n");
    printf("6.Pemain dapat memasukkan kartu lebih dari satu pada setiap turn asalkan enery masih cukup\n");
    printf("6.Board akan diupdate setelah kedua player menyelesaikan turn\n");
    printf("6.Pada akhir turn 6, setiap arena akan diadu power totalnya. Untuk setiap arena dengan total power lebih banyak, player yang memenagkan arena tersebut mendapatkan skor 1\n");
    printf("7.Player yang menang adalah player skor lebih banyak\n");
    printf("8. Jika skor seri, player yang menang adalah player dengan total power pada seluruh arena lebih besar\n");
    printf("Tekan Enter untuk keluar dari Guide: ");
    STARTCMD(false);
    system("cls");
}

void MARVELSNAP(){
    printDelay("WELCOME TO MARVEL SNAP\n",40);delay(500);
    boolean play = false;
    time_t waktu;
    srand(time(&waktu));
    int i,j;
    int turn = 1; // Turn ke berapa
    int Energyturn; //Energy turn
    Card kartu;
    Card kartu1, kartu2;
    boolean pemain1 = true; //Mengecek apakah giliran pemain 1
    boolean pemain2 = true; //Mengecek apakah giliran pemain 2
    boolean ended = false; //Mengecek apakah permainan sudah berakhir (Jika sudah menyelesaikan turn 6)
    ArrayCard Player1; MakeArrayCard(&Player1); //Menyimpan kartu yang dimiliki player 1
    ArrayCard Player2; MakeArrayCard(&Player2); //Menyimpan kartu yang dimiliki player 2
    ArrayInt PreArena1Player1; MakeArrayInt(&PreArena1Player1);
    ArrayInt PreArena2Player1; MakeArrayInt(&PreArena2Player1);
    ArrayInt PreArena3Player1; MakeArrayInt(&PreArena3Player1);
    ArrayInt PreArena1Player2; MakeArrayInt(&PreArena1Player2);
    ArrayInt PreArena2Player2; MakeArrayInt(&PreArena2Player2);
    ArrayInt PreArena3Player2; MakeArrayInt(&PreArena3Player2);
    ArrayInt Arena1Player1; MakeArrayInt(&Arena1Player1);
    ArrayInt Arena2Player1; MakeArrayInt(&Arena2Player1);
    ArrayInt Arena3Player1; MakeArrayInt(&Arena3Player1);
    ArrayInt Arena1Player2; MakeArrayInt(&Arena1Player2);
    ArrayInt Arena2Player2; MakeArrayInt(&Arena2Player2);
    ArrayInt Arena3Player2; MakeArrayInt(&Arena3Player2);
    while(!play){
        COMMANDGAME();
        system("cls");
        if(compareWord(currentCommand,"PLAY")){
            play = true;
        }
        else if(compareWord(currentCommand,"GUIDE")){
            PrintArena(Arena1Player1,Arena2Player1,Arena3Player1,Arena1Player2,Arena2Player2,Arena3Player2);
            PLAYGUIDE();
        }
        else{
            printf("Command tidak valid\n");
        }
    }

    printDelay("Prepare to Play\n",40);delay(500);
    system("cls");
    for(i=0;i<3;i++){
        kartu1.Energy = (rand()%(i+1)) + 1;
        kartu1.Power = CardPower(kartu1.Energy);
        InsertCardAt(&Player1,kartu1,Player1.Neff);
    }
    for(i=0;i<3;i++){
        kartu2.Energy = (rand()%(i+1)) + 1;
        kartu2.Power = CardPower(kartu2.Energy);
        InsertCardAt(&Player2,kartu2,Player2.Neff); 
    }
    printDelay("The Game has been started\n",25);delay(500);
    printDelay("Player 1 Turn",25);printDelay("...\n",200);
    printf("Tekan Enter untuk melanjutkan permainan: ");
    STARTCMD(false);
    system("cls");
    printf("-------------BOARD TURN 0------------------\n\n");
    PrintArena(PreArena1Player1,PreArena2Player1,PreArena3Player1,PreArena1Player2,PreArena2Player2,PreArena3Player2);
    insertRandomCard(&Player1);
    while(!ended){
        Energyturn = turn;
        while(pemain1){
            printf("Turn: %d\n",turn);
            printf("Player 1\n");
            PlayerTurn(&Energyturn,&pemain1, &pemain2, &Player1, &Arena1Player1, &Arena2Player1, &Arena3Player1);
            system("cls");
            printf("--------TEMPORARY BOARD TURN %d------------------\n\n",turn);
            PrintArena(Arena1Player1,Arena2Player1,Arena3Player1,PreArena1Player2,PreArena2Player2,PreArena3Player2);
        }
        system("cls");
        printDelay("Player 2 Turn",25);printDelay("...\n",200);
        printf("Tekan Enter untuk melanjutkan permainan: ");
        STARTCMD(false);
        system("cls");
        insertRandomCard(&Player2);
        printf("-------------BOARD TURN %d------------------\n\n",turn -1);
        PrintArena(PreArena1Player1,PreArena2Player1,PreArena3Player1,PreArena1Player2,PreArena2Player2,PreArena3Player2);
        Energyturn = turn;
        while(pemain2){
            printf("Turn: %d\n",turn);
            printf("Player 2\n");
            PlayerTurn(&Energyturn,&pemain2, &pemain1, &Player2, &Arena1Player2, &Arena2Player2, &Arena3Player2);
            system("cls");
            printf("--------TEMPORARY BOARD TURN %d------------------\n\n",turn);
            PrintArena(PreArena1Player1,PreArena2Player1,PreArena3Player1,Arena1Player2,Arena2Player2,Arena3Player2);
        }
        system("cls");

        turn +=1;
        if(turn == 7){
            printDelay("Game has ended\n",25);delay(500);
            printDelay("Calculating Score",40);printDelay("...\n",200);
            ended = true;
            pemain1 = false;
            pemain2 = false;
            PrintArena(Arena1Player1,Arena2Player1,Arena3Player1,Arena1Player2,Arena2Player2,Arena3Player2);
            skorakhir(Arena1Player1,Arena2Player1,Arena3Player1,Arena1Player2,Arena2Player2,Arena3Player2);
            printf("-------------GAME OVER------------------\n\n");
        }
        else{
            printDelay("Turn ",25);printf("%d ",turn - 1);printDelay("Ended\n",25);delay(1500);
            system("cls");
            printDelay("Turn ",25);printf("%d ",turn);printDelay("Begin\n",25);delay(1500);
            system("cls");
            printDelay("Player 1 Turn",25);printDelay("...\n",200);
            printf("Tekan Enter untuk melanjutkan permainan: ");
            STARTCMD(false);
            system("cls");
            insertRandomCard(&Player1);
            printf("-------------BOARD TURN %d------------------\n\n",turn-1);
            PrintArena(Arena1Player1,Arena2Player1,Arena3Player1,Arena1Player2,Arena2Player2,Arena3Player2);
            PreArena1Player1 = Arena1Player1;
            PreArena2Player1 = Arena2Player1;
            PreArena3Player1 = Arena3Player1;
            PreArena1Player2 = Arena1Player2;
            PreArena2Player2 = Arena2Player2;
            PreArena3Player2 = Arena3Player2;
        }
    }
}

void skorakhir(ArrayInt Arena1Player1, ArrayInt Arena2Player1, ArrayInt Arena3Player1,ArrayInt Arena1Player2, ArrayInt Arena2Player2, ArrayInt Arena3Player2){
    int skorPlayer1 = 0;
    int skorPlayer2 = 0;
    int PowerArena1Player1 = Arena1Player1.kekuatan[0] + Arena1Player1.kekuatan[1]+ Arena1Player1.kekuatan[2]+ Arena1Player1.kekuatan[3];
    int PowerArena2Player1 = Arena2Player1.kekuatan[0] + Arena2Player1.kekuatan[1]+ Arena2Player1.kekuatan[2]+ Arena2Player1.kekuatan[3];
    int PowerArena3Player1 = Arena3Player1.kekuatan[0] + Arena3Player1.kekuatan[1]+ Arena3Player1.kekuatan[2]+ Arena3Player1.kekuatan[3];
    int PowerArena1Player2 = Arena1Player2.kekuatan[0] + Arena1Player2.kekuatan[1]+ Arena1Player2.kekuatan[2]+ Arena1Player2.kekuatan[3];
    int PowerArena2Player2 = Arena2Player2.kekuatan[0] + Arena2Player2.kekuatan[1]+ Arena2Player2.kekuatan[2]+ Arena2Player2.kekuatan[3];
    int PowerArena3Player2 = Arena3Player2.kekuatan[0] + Arena3Player2.kekuatan[1]+ Arena3Player2.kekuatan[2]+ Arena3Player2.kekuatan[3]; 
    int PowerTotalPlayer1 = PowerArena1Player1 + PowerArena2Player1 + PowerArena3Player1;
    int PowerTotalPlayer2 = PowerArena1Player2 + PowerArena2Player2 + PowerArena3Player2;
    if(PowerArena1Player1 > PowerArena1Player2){
        skorPlayer1 +=1;
    }
    else if (PowerArena1Player1 < PowerArena1Player2){
        skorPlayer2 +=1;
    }
    if(PowerArena2Player1 > PowerArena2Player2){
        skorPlayer1 +=1;
    }
    else if (PowerArena2Player1 < PowerArena2Player2){
        skorPlayer2 +=1;
    }
    if(PowerArena3Player1 > PowerArena3Player2){
        skorPlayer1 +=1;
    }
    else if (PowerArena3Player1 < PowerArena3Player2){
        skorPlayer2 +=1;
    }
    if(skorPlayer1 > skorPlayer2){
        printf("Player 1 menang dengan skor %d - %d\n", skorPlayer1, skorPlayer2);
    }
    else if(skorPlayer1 < skorPlayer2){
        printf("Player 2 menang dengan skor %d - %d\n", skorPlayer2, skorPlayer1);
    }
    else{ //SkorPlayer1 = SkorPlayer 2
        if(PowerTotalPlayer1 > PowerTotalPlayer2){
            printf("TIEBREAKER!\n");
            printf("Player 1 menang dengan total power %d - %d\n",PowerTotalPlayer1, PowerTotalPlayer2);
        }
        else if(PowerTotalPlayer1 < PowerTotalPlayer2){
            printf("TIEBRAKER!\n");
            printf("Player 2 menang dengan total power %d - %d\n",PowerTotalPlayer2, PowerTotalPlayer1);
        }
        else{
            printf("PERMAINAN SERI\n");
        }
    }
}