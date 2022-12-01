#ifndef map_H
#define map_H
#include <stdio.h>
#include "../boolean.h"
#include "mesinkata.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define MaxMapEl 100
#define MaxListEl 20

// typedef int bool;
typedef Word keytype;
typedef int valuetype;
typedef int address;

typedef struct
{
	keytype Key;
	valuetype Value;
} mapinfo;

typedef struct
{
	mapinfo Elements[MaxMapEl];
	address Count;
} Map;

typedef struct
{
	Map board[MaxListEl];
	address Num;
} ListOfMap;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxMapEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmpty(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsMapFull(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxMapEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */

void MapValIns(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void MapValDel(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMapMember(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

void copyMap(Map S1, Map *S2);

void CreateEmptyMapList(ListOfMap *LM);

void SortByVal(Map *M);

#endif