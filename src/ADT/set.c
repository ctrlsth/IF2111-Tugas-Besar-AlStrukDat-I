#include <stdio.h>
#include "mesinkata.h"
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxSetEl */
/* Ciri Set kosong : count bernilai Nil */
{
    S->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsSetEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count == Nil;
}

boolean IsSetFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxSetEl */
{
    return S.Count == MaxSetEl;
}

/* ********** Operator Dasar Set ********* */
void InsertSetEl(Set *S, setinfo Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsSetMember(*S, Elmt))
    {
        return;
    }
    S->PlayerName[S->Count] = Elmt;
    S->Count++;
}

void DeleteSetEl(Set *S, setinfo Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    if (!IsSetMember(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count)
    {
        if (compare2Word(S->PlayerName[idx], Elmt))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < S->Count; iterator++)
    {
        S->PlayerName[iterator - 1] = S->PlayerName[iterator];
    }
    S->Count--;
}

boolean IsSetMember(Set S, setinfo Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    if (IsSetEmpty(S))
    {
        return false;
    }

    boolean found = false;
    address idx = 0, iterator;
    while (!found && idx < S.Count)
    {
        if (compare2Word(S.PlayerName[idx], Elmt))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}

void CreateEmptySetList(ListOfSet *LS)
{
    int i;
    for (i = 0; i < (LS->Num); i++)
    {
        CreateEmptySet(&(LS->GameSet[i]));
    }
    LS->Num = 6;
}

void SortSetByMap(Set *S, Map M)
{
    CreateEmptySet(S);
    int i;
    for (i = 0; i < M.Count; i++)
    {
        InsertSetEl(S, M.Elements[i].Key);
    }
}