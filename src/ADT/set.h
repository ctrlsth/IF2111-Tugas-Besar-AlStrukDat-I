#ifndef set_H
#define set_H

#include <stdio.h>
#include "../boolean.h"
#include "mesinkata.h"
#include "map.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define MaxSetEl 10
#define MaxListEl 20

typedef Word setinfo;
typedef int address;

typedef struct
{
    setinfo PlayerName[MaxSetEl];
    address Count;
} Set;

typedef struct
{
    Set GameSet[MaxListEl];
    address Num;
} ListOfSet;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.PlayerName = tempat penyimpanan nama pemain */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxSetEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsSetEmpty(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsSetFull(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxSetEl */

/* ********** Operator Dasar Set ********* */
void InsertSetEl(Set *S, setinfo Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetEl(Set *S, setinfo Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsSetMember(Set S, setinfo Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

void CreateEmptySetList(ListOfSet *LS);
/* I.S. Sembarang */
/* F.S. Membuat sebuah List of Set LS kosong berkapasitas capacity */
/* Ciri List of Set kosong :  LS->Num = Nil */

void SortSetByMap(Set *S, Map M);

#endif