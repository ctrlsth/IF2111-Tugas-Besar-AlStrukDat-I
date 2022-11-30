#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../boolean.h"
#include "../ADT/mesinkata.h"

#define IDX_UNDEF -1
#define MARKK '_'
#define KESEMPATAN 10

typedef struct {
    char kata[KESEMPATAN];
    int panjang;
} List;

//berhasil
void CreateList(List *LSoal, int digit){
    int i;
    for(i=0;i<digit;i++){
        LSoal->kata[i] = MARKK;
    }
}

//berhasil
void CreateEmpty(List *Lsalah){
    (*Lsalah).panjang = IDX_UNDEF;
}

//berhasil
int printSoal(int urutan){
    if (urutan == 1){
        printf("Di rumah makan Padang, selain pakai sendok kita makan pakai?\n");
    } else if (urutan == 2){
        printf("Seseorang yang memimpin sebuah desa, biasanya dipanggil pak?\n");
    } else if (urutan == 3){
        printf("Senikmat-nikmatnya makan di luar lebih nikmat makan di?\n");
    } else if (urutan == 4){
        printf("Ikan bernapas di air dengan?\n");
    } else if (urutan == 5){
        printf("Yang dibeli seorang cowok untuk pasangannya di saat Valentine biasanya?\n");
    } else if (urutan == 6){
        printf("Seorang barber mencukur rambut pelanggan dengan?\n");
    } else if (urutan == 7){
        printf("Lorenzo, Marquez, Rossi kejar-kejaran, salip menyalip di?\n");
    } else if (urutan == 8){
        printf("Burung bisa terbang karena memiliki?\n");
    } else if (urutan == 9){
        printf("Bendera NKRI warnanya?\n");
    } else if (urutan == 10){
        printf("Galang menyimpan buku di . . .\n");
    }
}

//berhasil
void variasiSoal(int urutan, List *L){
    if (urutan == 1){
        (*L).panjang = 6;
        (*L).kata[0] = 'T';
        (*L).kata[1] = 'E';
        (*L).kata[2] = 'N';
        (*L).kata[3] = 'A';
        (*L).kata[4] = 'G';
        (*L).kata[5] = 'A';
    } else if (urutan == 2){
        (*L).kata[0] = 'N';
        (*L).kata[1] = 'O';
        (*L).kata[2] = 'L';
        (*L).kata[3] = 'E';
        (*L).kata[4] = 'H';
        (*L).panjang = 5;
    } else if (urutan == 3){
        (*L).kata[0] = 'T';
        (*L).kata[1] = 'E';
        (*L).kata[2] = 'L';
        (*L).kata[3] = 'A';
        (*L).kata[4] = 'N';
        (*L).panjang = 5;
    } else if (urutan == 4){
        (*L).kata[0] = 'T';
        (*L).kata[1] = 'E';
        (*L).kata[2] = 'N';
        (*L).kata[3] = 'A';
        (*L).kata[4] = 'N';
        (*L).kata[5] = 'G';
        (*L).panjang = 6;
    } else if (urutan == 5){
        (*L).kata[0] = 'B';
        (*L).kata[1] = 'A';
        (*L).kata[2] = 'Y';
        (*L).kata[3] = 'A';
        (*L).kata[4] = 'R';
        (*L).panjang = 5;
    } else if (urutan == 6){
        (*L).kata[0] = 'G';
        (*L).kata[1] = 'A';
        (*L).kata[2] = 'N';
        (*L).kata[3] = 'T';
        (*L).kata[4] = 'I';
        (*L).kata[5] = 'A';
        (*L).kata[6] = 'N';
        (*L).panjang = 7;
    } else if (urutan == 7){
        (*L).kata[0] = 'B';
        (*L).kata[1] = 'I';
        (*L).kata[2] = 'A';
        (*L).kata[3] = 'R';
        (*L).kata[4] = 'K';
        (*L).kata[5] = 'A';
        (*L).kata[6] = 'N';
        (*L).panjang = 7;
    } else if (urutan == 8){
        (*L).kata[0] = 'B';
        (*L).kata[1] = 'A';
        (*L).kata[2] = 'K';
        (*L).kata[3] = 'A';
        (*L).kata[4] = 'T';
        (*L).panjang = 5;
    } else if (urutan == 9){
        (*L).kata[0] = 'C';
        (*L).kata[1] = 'U';
        (*L).kata[2] = 'M';
        (*L).kata[3] = 'A';
        (*L).kata[4] = 'D';
        (*L).kata[5] = 'U';
        (*L).kata[6] = 'A';
        (*L).kata[7] = 'A';
        (*L).kata[8] = 'J';
        (*L).kata[9] = 'A';
        (*L).panjang = 10;
    } else if (urutan == 10){
        (*L).kata[0] = 'M';
        (*L).kata[1] = 'A';
        (*L).kata[2] = 'S';
        (*L).panjang = 3;
    }
}

//berhasil
void TampilanGaris(List Lsalah){
    if (Lsalah.panjang == 1){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 2){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 3){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 4){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 5){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 6){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  /       ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 7){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  / \'    ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 8){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  /|\'    ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 9){
        printf("======================================\n");
        printf("        EHH KOK GUA DISINI!!??        \n");
        printf("             TOLONGGG!!!              \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  /|\'    ||          \n");
        printf("                  /       ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 10){
        printf("======================================\n");
        printf("            TIIIIDAAAAKKK!!!!!!       \n");
        printf("        AARGHHH!!     AAAAAARGHHH!!   \n");
        printf("     AAAARGHHH!!   -------||  ARGHH!  \n");
        printf("        AARGHHH!!  O      || ARGHH!   \n");
        printf("     AAAARGHHH!!  /|\'    ||  ARGHH!  \n");
        printf("        AARGHHH!! / \'    || ARGHH!   \n");
        printf("     AAAARGHHH!!          ||  ARGHH!  \n");
        printf("======================================\n");
    }
}


void DeleteAt(List *Lbenar, List LSoal, int indeks){
    int j;
    for(j=indeks;j<=LSoal.panjang;j++){
        (*Lbenar).kata[j] = (*Lbenar).kata[j+1];
    }
}


//berhasil
void InsertAt(List *Lbenar, List LSoal, int indeks){
    int j;
    List Lbenartemp;
    for(j=indeks;j<=LSoal.panjang;j++){
        (Lbenartemp).kata[j] = (*Lbenar).kata[j];
    }
    for(j=indeks;j<=LSoal.panjang;j++){
        (*Lbenar).kata[j+1] = (Lbenartemp).kata[j];
    }
    (*Lbenar).kata[indeks] = LSoal.kata[indeks];
}

//
void DigitBenar(List *LSoal, char huruf, List *Lsalah, List *Lbenar){
    int i = 0;
    int count = 0;
    while (i<(*LSoal).panjang ){
        if((*LSoal).kata[i] == huruf){
            DeleteAt(Lbenar, *LSoal, i);
            InsertAt(Lbenar, *LSoal, i);
            (*Lbenar).panjang--;
            count++;
        } 
        i++;
    }
    if(count==0){
        (*Lsalah).kata[(*Lsalah).panjang] = huruf;
        (*Lsalah).panjang++;
    }

}

//berhasil
void PrintList(List L, int max){
    int i;
    for(i=0;i<max;i++){
        printf("%c", (L).kata[i]);
    }
}

//berhasil
void TampilanGame(List Lbenar ,List Lsalah, int urutan, List LSoal){
    TampilanGaris(Lsalah);
    printSoal(urutan);
    printf("==========================================================================================\n");

    printf("Tebakan sebelumnya : \n");
    PrintList(Lsalah, Lsalah.panjang);
    printf("\n");
    printf("Kata : \n");
    PrintList(Lbenar, LSoal.panjang);
    printf("\n");
    printf("Kesempatan : ");
    printf("%d", (10-(Lsalah).panjang));
    printf("\n");
    printf("==========================================================================================\n");
}

//berhasil
boolean isExist (char huruf, List Lsalah, List Lbenar, List LSoal){
    boolean found = false;
    int i=0;
    while (i<KESEMPATAN && !found){
        if (huruf == Lsalah.kata[i] || huruf == Lbenar.kata[i]){
            found = true;
        }
        i++;
    }
    return found;
}

//berhasil
boolean IsFinished (List Lsalah, List Lbenar, List LSoal){
    return (Lbenar.panjang == 0 || Lsalah.panjang > KESEMPATAN);
}

/*
int main() {
    printf("==========================================================================================\n");
    printf("Selamat datang di game hangman!!\nSemoga kamu ga menyesal bermain game ini!!");

    char input;
    int point=0;
    List LSoal;
    List Lsalah;
    List Lbenar;
    srand(time(0));
    int urutan = (rand()%10) + 1;

    CreateEmpty(&LSoal);
    variasiSoal(urutan, &LSoal);
    CreateList(&Lbenar, LSoal.panjang);
    CreateEmpty(&Lsalah);
    Lbenar.panjang = LSoal.panjang;
    Lsalah.panjang = 0;

    printf("\n");
    TampilanGame(Lbenar, Lsalah, urutan);
    printf("\nMasukan Tebakan : ");
    scanf("%c\n", &input);
    while(!((int) input >= 'A' && (int) input <= 'Z')){
        printf("Sori bro, coba situ input hurufnya di capslocskin dlu truss inputnya harus berupa huruf yakk!\n");
        printf("Masukan Tebakan : ");
        scanf("%c\n", &input);
    }
    DigitBenar(LSoal, input, Lsalah, Lbenar);
    while(!IsFinished(Lsalah, Lbenar, LSoal)){
        TampilanGame(Lbenar, Lsalah, urutan);
        printf("Masukan Tebakan : ");
        scanf("%c\n", &input);
            while(!((int) input >= 'A' && (int) input <= 'Z') || (isExist(input, Lsalah, Lbenar, LSoal))){
                printf("Sori bro, coba situ input hurufnya di capslocsk dan tentu inputnya harus huruf yakk!\n");
                printf("btw, inputnya jangan huruf yang udh pernah ditebak yakk!!!\n");
                TampilanGame(Lbenar, Lsalah, urutan);
                printf("Masukan Tebakan : ");
        }
        DigitBenar(LSoal, input, Lsalah, Lbenar);
    }
    if (Lbenar.panjang == LSoal.panjang){
        printf("WADAWWW.. SITU KEREN BANGET BISA MENANGIN NI GAME!!\n");
        printf("Karena situ udh menang, aku kasi situ %d point dehhh!!\n", point);
    } else if (Lsalah.panjang > KESEMPATAN){
        printf("YAHAHHAA!!!\n");
        printf("Cupssss!!\n");
    }
    return 0;
}
*/
int main (){

    List LSoal;
    List Lbenar;
    List Lsalah;
    srand(time(0));
    int point;
    int urutan = (rand()%10) + 1;

    printf("%d\n", urutan);
    CreateEmpty(&LSoal);
    variasiSoal(urutan, &LSoal);
    CreateList(&Lbenar, LSoal.panjang);
    CreateEmpty(&Lsalah);

    Lsalah.panjang = 0;
    Lbenar.panjang = LSoal.panjang;
    point = LSoal.panjang;
    
    // printf("%d\n", LSoal.panjang);
    // printf("%d\n", Lbenar.panjang);
    // printf("%d\n", Lsalah.panjang);

    printf("\n");
    printf("  /$$$$$$            /$$                                     /$$           /$$                          \n");
    printf(" /$$__  $$          | $$                                    | $$          | $$                          \n");
    printf("| $$  \__/  /$$$$$$ | $$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$  /$$$$$$        | $$$$$$$   /$$$$$$   /$$$$$$ \n");
    printf("|  $$$$$$  /$$__  $$| $$ |____  $$| $$_  $$_  $$ |____  $$|_  $$_/        | $$__  $$ /$$__  $$ /$$__  $$\n");
    printf(" \____  $$| $$$$$$$$| $$  /$$$$$$$| $$ \ $$ \ $$  /$$$$$$$  | $$          | $$  \ $$| $$$$$$$$| $$  \__/\n");
    printf(" /$$  \ $$| $$_____/| $$ /$$__  $$| $$ | $$ | $$ /$$__  $$  | $$ /$$      | $$  | $$| $$_____/| $$      \n");
    printf("|  $$$$$$/|  $$$$$$$| $$|  $$$$$$$| $$ | $$ | $$|  $$$$$$$  |  $$$$/      | $$$$$$$/|  $$$$$$$| $$      \n");
    printf(" \______/  \_______/|__/ \_______/|__/ |__/ |__/ \_______/   \___/        |_______/  \_______/|__/      \n");
    printf("\n");
    printf("\n");
    printf("             /$$   /$$  /$$$$$$  /$$   /$$  /$$$$$$  /$$      /$$  /$$$$$$  /$$   /$$                   \n");
    printf("            | $$  | $$ /$$__  $$| $$$ | $$ /$$__  $$| $$$    /$$$ /$$__  $$| $$$ | $$                   \n");
    printf("            | $$  | $$| $$  \ $$| $$$$| $$| $$  \__/| $$$$  /$$$$| $$  \ $$| $$$$| $$                   \n");
    printf("            | $$$$$$$$| $$$$$$$$| $$ $$ $$| $$ /$$$$| $$ $$/$$ $$| $$$$$$$$| $$ $$ $$                   \n");
    printf("            | $$__  $$| $$__  $$| $$  $$$$| $$|_  $$| $$  $$$| $$| $$__  $$| $$  $$$$                   \n");
    printf("            | $$  | $$| $$  | $$| $$\  $$$| $$  \ $$| $$\  $ | $$| $$  | $$| $$\  $$$                   \n");
    printf("            | $$  | $$| $$  | $$| $$ \  $$|  $$$$$$/| $$ \/  | $$| $$  | $$| $$ \  $$                   \n");
    printf("            |__/  |__/|__/  |__/|__/  \__/ \______/ |__/     |__/|__/  |__/|__/  \__/                   \n");
    printf("\n");
    printf("\n");
    printf("                                         /$$           /$$ /$$                                          \n");
    printf("                                        |__/          | $$| $$                                          \n");
    printf("                                /$$$$$$  /$$  /$$$$$$ | $$| $$                                          \n");
    printf("                               /$$__  $$| $$ |____  $$| $$| $$                                          \n");
    printf("                              | $$  \__/| $$  /$$$$$$$|__/|__/                                          \n");
    printf("                              | $$      | $$ /$$__  $$                                                  \n");
    printf("                              | $$      | $$|  $$$$$$$ /$$ /$$                                          \n");
    printf("                              |__/      |__/ \_______/|__/|__/                                          \n");
    printf("\n");
    printf("\n");
    
    TampilanGame(Lbenar, Lsalah, urutan, LSoal);
    printf("Masukan Tebakanmu : ");
    STARTCMD(true);
    Word Uinput = currentCommand;
    char input = Uinput.TabChar[0];
    //scanf("%c", &input);
    printf("\n");
    //printf("%c", input);
    while(!(input >= 'A' && input <= 'Z')){
        printf("******************************************************************************************\n");
        printf("Sori bro, coba situ input hurufnya di capslocskin dlu truss inputnya harus berupa huruf yakk!\n");
        printf("******************************************************************************************\n");
        printf("Masukan Tebakanmu : ");
        scanf("%c", &input);
        printf("\n");
    }
    DigitBenar(&LSoal, input, &Lsalah, &Lbenar);
    while(!IsFinished(Lsalah, Lbenar, LSoal)){
        TampilanGame(Lbenar, Lsalah, urutan, LSoal);
        printf("Masukan Tebakanmu : ");
        scanf(" %c", &input);
        printf("\n");
        while(!(input >= 'A' && input <= 'Z') || (isExist(input, Lsalah, Lbenar, LSoal))){
            printf("******************************************************************************************\n");
            if((isExist(input, Lsalah, Lbenar, LSoal))){
                printf("btw, inputnya jangan huruf yang udh pernah ditebak yakk!!!\n");
            }
            else{
                printf("Sori bro, coba situ input hurufnya di capslocsk dan tentu inputnya harus huruf yakk!\n");
            }
            printf("******************************************************************************************\n");
            printf("Masukan Tebakanmu : ");
            scanf(" %c", &input);
            printf("\n");       
        }
        DigitBenar(&LSoal, input, &Lsalah, &Lbenar);
    }

    if(Lbenar.panjang == 0){
        printf("WADAWWW.. SITU KEREN BANGET BISA MENANGIN NI GAME!!\n");
        printf("Karena situ udh menang, aku kasi situ %d point dehhh yakk!!\n", point);
    } else if(Lsalah.panjang > KESEMPATAN){
        printf("YAHAHHAA!!!\n");
        printf("MAAF ANDA KURANG BERUNTUNG. SARAN KAMI SIH COBA LAGI (TAUN DPN YA!!)");
    }

    return 0;
}