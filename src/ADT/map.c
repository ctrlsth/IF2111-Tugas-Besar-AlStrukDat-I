#include <stdio.h>
#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxMapEl */
/* Ciri Map kosong : count bernilai Nil */
{
    M->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmpty(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.Count == Nil;
}

boolean IsMapFull(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxMapEl */
{
    return M.Count == MaxMapEl;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
{
    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M.Count)
    {
        if (compare2Word(M.Elements[idx].Key, k))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }

    return M.Elements[idx].Value;
}

void MapValIns(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (IsMapMember(*M, k))
    {
        return;
    }

    M->Elements[M->Count].Key = k;
    M->Elements[M->Count].Value = v;
    M->Count++;
}

void MapValDel(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    boolean found = false;
    address idx = 0, iterator;

    if (!IsMapMember(*M, k))
    {
        return;
    }

    while (!found && (idx < M->Count))
    {
        if (compare2Word(M->Elements[idx].Key, k))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }

    for (iterator = (idx + 1); iterator < M->Count; iterator++)
    {
        M->Elements[iterator - 1].Key = M->Elements[iterator].Key;
        M->Elements[iterator - 1].Value = M->Elements[iterator].Value;
    }

    M->Count--;
}

boolean IsMapMember(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    if (IsMapEmpty(M))
    {
        return false;
    }

    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M.Count)
    {
        if (compare2Word(M.Elements[idx].Key, k))
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

void copyMap(Map S1, Map *S2)
{
    int i;
    for (i = 0; i < S1.Count; i++)
    {
        S2->Elements[i].Key = S1.Elements[i].Key;
        S2->Elements[i].Value = S1.Elements[i].Value;
    }

    S2->Count = S1.Count;
}

void CreateEmptyMapList(ListOfMap *LM)
{
    int i;
    for (i = 0; i < MaxListEl; i++)
    {
        CreateEmptyMap(&(LM->board[i]));
    }
    LM->Num = 6;
}

void SortByVal(Map *M)
{
    Map sortedMap;
    CreateEmptyMap(&sortedMap);

    int k;
    printf("Before Update (M): \n");
    for (k = 0; k < M->Count; k++)
    {
        printWord(M->Elements[k].Key);
        printf(" - %d\n", M->Elements[k].Value);
    }
    printf("\n");
    printf("Before Update (sortedMap): \n");
    for (k = 0; k < sortedMap.Count; k++)
    {
        printWord(sortedMap.Elements[k].Key);
        printf(" - %d\n", sortedMap.Elements[k].Value);
    }
    printf("\n");


    while (!IsMapEmpty((*M)))
    {
        valuetype max = M->Elements[0].Value;
        keytype maxkey = M->Elements[0].Key;

        int i;
        for (i = 1; i < M->Count; i++)
        {
            if (M->Elements[i].Value > max)
            {
                max = M->Elements[i].Value;
                maxkey = M->Elements[i].Key;
            }
        }

        MapValIns(&sortedMap, maxkey, max);
        MapValDel(M, maxkey);
    }

    printf("After Update (M): \n");
    for (k = 0; k < M->Count; k++)
    {
        printWord(M->Elements[k].Key);
        printf(" - %d\n", M->Elements[k].Value);
    }
    printf("\n");
    printf("After Update (sortedMap): \n");
    for (k = 0; k < sortedMap.Count; k++)
    {
        printWord(sortedMap.Elements[k].Key);
        printf(" - %d\n", sortedMap.Elements[k].Value);
    }
    printf("\n");

    copyMap(sortedMap, M);
}