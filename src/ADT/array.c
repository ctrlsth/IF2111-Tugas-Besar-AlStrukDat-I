
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk TabWord kosong dengan ukuran InitialSize
 */
void MakeTabWord(TabWord *Array)
{
	Array->TW = (ElType *)malloc(InitialSize * sizeof(ElType));
	Array->Capacity = InitialSize;
	Array->Neff = 0;
}

/**
 * Destruktor
 * I.S. TabWord terdefinisi
 * F.S. array->TW terdealokasi
 */
void DeallocateTabWord(TabWord *array)
{
	free(array->TW);
	array->Neff = 0;
	array->Capacity = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(TabWord array)
{
	return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(TabWord array)
{
	return (array.Neff);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(TabWord array, IdxType i)
{
	return (array.TW[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(TabWord array)
{
	return (array.Capacity);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(TabWord *array, ElType el, IdxType i)
{
	int j;

	/* Penambahan ukuran array, jika array sudah penuh */
	if (Length((*array)) == GetCapacity(*array))
	{
		/* Inisialisasi Temporary */
		int newCap, susNeff;
		ElType *sus;

		/* Pemindahan isi array ke Temporary: sus */
		newCap = GetCapacity((*array)) + InitialSize;
		sus = (ElType *)malloc(newCap * sizeof(ElType));
		for (j = 0; j < Length((*array)); j++)
		{
			sus[j] = array->TW[j];
		}
		susNeff = Length((*array));

		/* Relokasi array */
		DeallocateTabWord(array);
		array->TW = (ElType *)malloc(newCap * sizeof(ElType));
		array->Capacity = newCap;
		array->Neff = susNeff;

		/* Mengisi kembali array dari Temporary: sus */
		for (j = 0; j < newCap; j++)
		{
			array->TW[j] = sus[j];
		}

		/* Dealokasi Temporary: sus */
		free(sus);
	}

	/* Penyisipan elemen baru */
	for (j = Length((*array)); j > i; j--)
	{
		array->TW[j] = array->TW[j - 1];
	}

	array->TW[i] = el;
	array->Neff += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(TabWord *array, ElType el)
{
	InsertAt(array, el, Length((*array)));
}

/**
 * Fungsi untuk menghapus elemen di index ke-i TabWord
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(TabWord *array, IdxType i)
{
	int j;
	for (j = i; j <= Length((*array)); j++)
	{
		array->TW[j] = array->TW[j + 1];
	}

	array->Neff -= 1;
}

/**
 * Fungsi untuk menghapus elemen pertama TabWord
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(TabWord *array)
{
	DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu TabWord.
 * Prekondisi: array terdefinisi
 */
void PrintTabWord(TabWord array)
{
	int i;
	if (Length(array) != 0)
	{
		printf("Berikut adalah daftar game yang tersedia\n");
		for (i = 0; i < Length(array); i++)
		{
			printf("%d. ", i + 1);
			printWord(array.TW[i]);
			printf("\n");
		}
	}
	else
	{
		printf("Tidak ada game dalam yang terdaftar.\n");
	}
}

/**
 * Fungsi untuk melakukan copy suatu TabWord.
 * Prekondisi: array terdefinisi
 */
TabWord CopyTabWord(TabWord array)
{
	TabWord newArray;
	int i;
	MakeTabWord(&newArray);
	newArray.Capacity = array.Capacity;
	newArray.Neff = array.Neff;
	for (i = 0; i < Length(array); i++)
	{
		newArray.TW[i] = array.TW[i];
	}
	return newArray;
}

/**
 * Fungsi untuk melakukan search suatu TabWord.
 * Prekondisi: array terdefinisi
 */
IdxType SearchTabWord(TabWord array, ElType el)
{
	int i = 0;
	while (i < Length(array))
	{
		if (compare2Word(Get(array, i), el))
		{
			return i;
		}
		i++;
	}
	return (-1);
}