#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void CreateEmpty(Stack *S)
{
    /* I.S. sembarang; */
    /* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
    /* jadi indeksnya antara 0.. MaxElStack */
    /* Ciri stack kosong : TOP bernilai Nil */
    // KAMUS

    // ALGORITMA
    S->T = (stacktype*) malloc(MaxElStack *sizeof(stacktype));
    Top(*S) = Nil;
    S->Capacity = MaxElStack;
}

boolean IsEmptyStack(Stack S)
{
    /* Mengirim true jika Stack kosong: lihat definisi di atas */

    // KAMUS

    // ALGORITMA
    return Top(S) == Nil;
}

void MakeEmptyStack(Stack *S)
{
    /* I.S. S sudah terdefinisi sebelumnya */
    /* F.S. Menghapus semua elemen stack dan mendealokasi elemen-elemen stack
            S menjadi kosong */

    /* KAMUS */
    stacktype pop;

    /* ALGORITMA */
    while (!IsEmptyStack(*S))
    {
        Pop(S, &pop);
    }
    free(S->T);
    Top(*S) = Nil;
    S->Capacity = 0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsFullStack(Stack S)
{
    /* Mengirim true jika tabel penampung nilai elemen stack penuh */

    // KAMUS

    // ALGORITMA
    return Top(S) == S.Capacity - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, stacktype X)
{
    int j;
    /* Menambahkan X sebagai elemen Stack S. */
    /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
    /* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

    // KAMUS

    // ALGORITMA
    if (IsEmptyStack(*S))
    {
        Top(*S) = 0;
    }
    else
    {
        if(IsFullStack(*S)){
            int newCap, susTOP;
            stacktype *sus;

            /* Pemindahan isi array ke Temporary: sus */
            newCap = S->Capacity + MaxElStack;
            sus = (stacktype *)malloc(newCap * sizeof(stacktype));
            for (j = 0; j <= S->TOP; j++)
            {
                sus[j] = S->T[j];
            }
            susTOP = S->TOP;

            /* Relokasi array */
            MakeEmptyStack(S);
            S->T = (stacktype *)malloc(newCap * sizeof(stacktype));
            S->Capacity = newCap;
            S->TOP = susTOP;

            /* Mengisi kembali array dari Temporary: sus */
            for (j = 0; j < newCap; j++)
            {
                S->T[j] = sus[j];
            }
            free(sus);

        }
        Top(*S) += 1;
    }
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, stacktype *X)
{
    /* Menghapus X dari Stack S. */
    /* I.S. S  tidak mungkin kosong */
    /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

    // KAMUS

    // ALGORITMA
    *X = InfoTop(*S);
    Top(*S) -= 1;
}

void DeleteStackAt(Stack *S, int i){
    int j;
	for (j = i; j <= Top(*S); j++)
	{
		S->T[j] = S->T[j + 1];
	}
	S->TOP -= 1;
}