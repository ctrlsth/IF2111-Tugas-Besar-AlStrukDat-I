#include <stdio.h>
#include <time.h>
#include "../boolean.h"

const char MARK = '_';
const int KESEMPATAN = 10;

typedef struct {
    char* kata[KESEMPATAN];
    int panjang;
} List;

void CreateList1 (List *LSoal, int digit){
    int i;
    for(i=0;i<digit;i++){
        LSoal->kata[i] = MARK;
    }
}

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
        printf("Galang menyimpan buku di…\n");
    }
}

void variasiSoal(int urutan, List L){
    if (urutan == 1){
        L.panjang = 6;
        L.kata[0] = "T";
        L.kata[1] = "E";
        L.kata[2] = "N";
        L.kata[3] = "A";
        L.kata[4] = "G";
        L.kata[5] = "A";
    } else if (urutan == 2){
        L.kata[0] = "N";
        L.kata[1] = "O";
        L.kata[2] = "L";
        L.kata[3] = "E";
        L.kata[4] = "H";
        L.panjang = 5;
    } else if (urutan == 3){
        L.kata[0] = "T";
        L.kata[1] = "E";
        L.kata[2] = "L";
        L.kata[3] = "A";
        L.kata[4] = "N";
        L.panjang = 5;
    } else if (urutan == 4){
        L.kata[0] = "T";
        L.kata[1] = "E";
        L.kata[2] = "N";
        L.kata[3] = "A";
        L.kata[4] = "N";
        L.kata[5] = "G";
        L.panjang = 6;
    } else if (urutan == 5){
        L.kata[0] = "B";
        L.kata[1] = "A";
        L.kata[2] = "Y";
        L.kata[3] = "A";
        L.kata[4] = "R";
        L.panjang = 5;
    } else if (urutan == 6){
        L.kata[0] = "G";
        L.kata[1] = "A";
        L.kata[2] = "N";
        L.kata[3] = "T";
        L.kata[4] = "I";
        L.kata[5] = "A";
        L.kata[6] = "N";
        L.panjang = 7;
    } else if (urutan == 7){
        L.kata[0] = "B";
        L.kata[1] = "I";
        L.kata[2] = "A";
        L.kata[3] = "R";
        L.kata[4] = "K";
        L.kata[5] = "A";
        L.kata[6] = "N";
        L.panjang = 7;
    } else if (urutan == 8){
        L.kata[0] = "B";
        L.kata[1] = "A";
        L.kata[2] = "K";
        L.kata[3] = "A";
        L.kata[4] = "T";
        L.panjang = 5;
    } else if (urutan == 9){
        L.kata[0] = "C";
        L.kata[1] = "U";
        L.kata[2] = "M";
        L.kata[3] = "A";
        L.kata[4] = "D";
        L.kata[5] = "U";
        L.kata[6] = "A";
        L.kata[7] = "A";
        L.kata[8] = "J";
        L.kata[9] = "A";
        L.panjang = 10;
    } else if (urutan == 10){
        L.kata[0] = "M";
        L.kata[1] = "A";
        L.kata[2] = "S";
        L.panjang = 3;
    }
}

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
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  /|\'    ||          \n");
        printf("                  /       ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 10){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  /|\'    ||          \n");
        printf("                  / \'    ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    }
}

void DeleteAt(List *Lbenar, List LSoal, int indeks){
    int j;
    for(j=indeks;j<=LSoal.panjang;j++){
        (*Lbenar).kata[j] = (*Lbenar).kata[j+1];
    }
}

void InsertAt(List *Lbenar, List LSoal, int indeks){
    int j;
    for(j=indeks;j<=LSoal.panjang;j++){
        (*Lbenar).kata[j+1] = (*Lbenar).kata[j];
    }
    (*Lbenar).kata[indeks] = LSoal.kata[indeks];
}

void DigitBenar(List LSoal, char huruf, List Lsalah, List Lbenar){
    int i = 0;
    while (i<LSoal.panjang){
        if(LSoal.kata[i] == huruf){
            DeleteAt(&Lbenar, LSoal, i);
            InsertAt(&Lbenar, LSoal, i);
            Lbenar.panjang++;
            i++;
        } else {
            InsertAt(&Lsalah, LSoal, Lsalah.panjang);
            Lsalah.panjang++;
        }
    }
}

void PrintList(List L){
    int i;
    for(i=0;i<(L).panjang;i++){
        printf("%c", (L).kata[i]);
    }
}

void TampilanGame(List Lbenar ,List *Lsalah, int urutan){
    TampilanGaris(*Lsalah);
    printSoal(urutan);
    printf("Tebakan sebelumnya : ");
    PrintList(*Lsalah);
    printf("\nKata : ");
    PrintList(Lbenar);
    printf("\nKesempatan : ");
    printf("%d", (10-(*Lsalah).panjang));
    printf("\nMasukan tebakan : ");
}


boolean IsFinished (List Lsalah, List Lbenar, List LSoal){
    return (Lbenar.panjang == LSoal.panjang || Lsalah.panjang > KESEMPATAN);
}

int main() {
    printf("Selamat datang di game hangman!!\n Semoga kamu ga menyesal bermain game ini!!");
    char input;
    int point=0;
    srand(time(0));
    List LSoal;
    List Lsalah;
    List Lbenar;
    Lbenar.panjang = 0;
    Lsalah.panjang = 0;
    int urutan = (rand()%10) + 1;
    variasiSoal(urutan, LSoal);
    CreateList1(&LSoal, LSoal.panjang);
    TampilanGame(Lbenar, &Lsalah, urutan);
    scanf("%c", &input);
    DigitBenar(LSoal, input, Lsalah, Lbenar);
    while(!IsFinished){
        TampilanGame(Lbenar, &Lsalah, urutan);
        scanf("%c", &input);
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