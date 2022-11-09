
#include "../boolean.h"
#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty(TabWord *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    // printf("Start MakeEmpty\n");
    (*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabWord T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl(TabWord T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabWord T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return IdxMin;
}

IdxType GetLastIdx(TabWord T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
    return NbElmt(T);
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt(TabWord T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
    return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab(TabWord Tin, TabWord *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
    (*Tout) = Tin;
}

void SetEl(TabWord *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
    T->TI[i] = v;
    T->Neff++;
}

void SetNeff(TabWord *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
    T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabWord T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= IdxMin) && (i <= IdxMax);
}

boolean IsIdxEff(TabWord T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i >= GetFirstIdx(T)) && (i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabWord T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (NbElmt(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull(TabWord T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (NbElmt(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi(TabWord T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Contoh hasil print isi
   1. lmao pisan
   2. sussy amogus */

{
    printf("@ Felisa Edit this Part for List Game");
    if (IsEmpty(T)){
        printf("T kosong");
    }
    else{
        for (int i=0; i< NbElmt(T); i++){
            printf("%d", i+1);
            printf("%s\n", T.TI[i]);
//             for (int j=0; j<T.TI[i].length; j++){
//                 printf("%c", T.TI[i].TabWord[j]);
//             }
        }
    }
}
