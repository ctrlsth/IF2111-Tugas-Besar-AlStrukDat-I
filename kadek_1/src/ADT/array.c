// NIM      : 18221047
// Nama     : I Dewa Made Manu Pradnyana
// Tanggal  : 19 Oktober 2022
// Topik praktikum  : PraPraktikum 03 - arraydin.c
// Deskripsi : Realisasi fungsi arraydin.h

#include "array.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
void MakeArrayDin(ArrayDin *array){
    array->A = (ElType*) malloc (InitialSize * (sizeof(ElType)));
    array->Capacity = InitialSize;
    array->Neff = 0;
}

// void MakeArrayChar(chardin *kata){
//     (*kata) = (chardin*) malloc (charsize * (sizeof(chardin)));
// }
// void InsertcharLast(chardin *kata, char huruf){
//     int length = 0;
//     while (kata[length] != '\0')
//     {
//         length++;
//     }
// }

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i){
    return(array.A[i]);
}

// ElType toEltype(Kata kata){
//     ElType eltype;
//     int i;
//     for(i=0;i<kata.Length;i++){
//         eltype.buffer[i] = kata.TabKata[i];
//     }
//     eltype.length = kata.Length;
//     return eltype;
// }

boolean compareWord(ElType kata1, char *kata2)
/* Membandingkan sebuah word dengan sebuah sting
   True     : Jika string dan kata sama,
   False    : Jika berbeda */
{
    boolean same = false;
    if (kata1.Length == strLength(kata2))
    {
        int i = 0;
        same = true;
        while (i < kata1.Length && (same))
        {
            if (kata1.TabKata[i] != kata2[i])
            {
                same = false;
            }
            i++;
        }
    }
    return same;
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */


void InsertAt(ArrayDin *array, ElType el, IdxType i){
    int length = Length(*array);
    int capacity = GetCapacity(*array);
    if (length == capacity){
        int desiredCapacity = capacity + InitialSize; 
        ElType *arr = (ElType*) malloc(desiredCapacity * (sizeof(ElType)));
        for (int j = 0;j < length; j++){
            arr[j] = Get(*array,j);
        }
        free(array->A);
        array->A = arr;
        array->Capacity = desiredCapacity;
    }   
    for (int j=length -1; j >= i;j--){
        (*array).A[j+1] = (*array).A[j];
    }
    array->A[i] = el;
    array->Neff+=1;
}

void increaseCapacity(ArrayDin* array){
    if (array->Neff == array->Capacity){
        int desiredCapacity = array->Neff + InitialSize; 
        ElType *arr = (ElType*) malloc(desiredCapacity * (sizeof(ElType)));
        for (int j = 0;j < array->Neff; j++){
            arr[j] = Get(*array,j);
        }
        free(array->A);
        array->A = arr;
        array->Capacity = desiredCapacity;
    }   
}
/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el){
    InsertAt(array, el, Length(*array));
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el){
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i){
    int length = Length(*array);
    for (int j = i; j < length - 1;j++){
        array->A[j]=array->A[j+1];
    }
    array->Neff -=1;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array){
    DeleteAt(array, Length(*array)-1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array){
    DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array){
    int i,j;
    if (IsEmpty(array)){
        printf("\n");
    }
    else{
        for (i=0;i<array.Neff;i++){
            printf("%d. ",i + 1);
            for(j=0;j<array.A[i].Length;j++){
                printf("%c",array.A[i].TabKata[j]);
            }
            printf("\n");
        }
    }
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array){
    int length = Length(*array);
    ElType temp;
    for (int i=0;i<(length/2);i++){
        temp = array->A[i];
        array->A[i] = array->A[length-1-i];
        array->A[length-1-i] = temp;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array){
    ArrayDin copy;
    MakeArrayDin(&copy);
    for (int i = 0; i < array.Neff;i++){
        InsertLast(&copy, array.A[i]);
    }
    return copy;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
// IdxType SearchArrayDin(ArrayDin array, ElType el){
//     int i = 0;
//     IdxType indeks;
//     while((array.A[i] != el) && (i<Length(array)-1)){
//         i +=1;
//     }
//     if (array.A[i] == el){
//         indeks = i;
//     }
//     else{
//         indeks = -1;
//     }
//     return indeks;
// }

boolean COMMAND_START_LOAD_ETC(boolean mainmenu, ArrayDin array){
    boolean bool = false;
    if (!mainmenu){ //belum masuk mainmenu tapi ingin menjalankan command selain start load quit help
        if (array.Neff == 2){
            if (compareWord(array.A[0],"LIST") && compareWord(array.A[1],"GAME")){
                bool = true;
            }
            else if (compareWord(array.A[0],"CREATE") && compareWord(array.A[1],"GAME")){
                bool = true;
            }
            else if (compareWord(array.A[0],"DELETE") && compareWord(array.A[1],"GAME")){
                bool = true;
            }
            else if (compareWord(array.A[0],"QUEUE") && compareWord(array.A[1],"GAME")){
                bool = true;
            }
            else if (compareWord(array.A[0],"PLAY") && compareWord(array.A[1],"GAME")){
                bool = true;
            }
            else if (compareWord(array.A[0], "SKIPGAME")){
                bool = true;
            }
            else if (compareWord(array.A[0],"SAVE")){
                bool = true;
            }
        }
    }
    else{
        if (array.Neff == 1){
            if(compareWord(array.A[0],"START")){
                bool = true;
            }
        }
        else if (array.Neff == 2){
            if(compareWord(array.A[0],"LOAD")){
                bool = true;
            }
        }    
    }
    return bool;
}