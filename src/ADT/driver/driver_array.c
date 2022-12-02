#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main (){
    TabWord Teks, Salinan;

    MakeTabWord(&Teks);
    int Panjang = Length(Teks);
    if (IsEmpty(Teks)){
        printf("Panjang array efektif : %d", Panjang);
        int i = 0;
        ElType Uji1 = toWord("Sama");
        InsertFirst(&Teks, Uji1);
        while (i < Panjang){
            InsertLast(&Teks, Uji1);
            i++;
        }
        Uji1 = toWord("Selipan");
        InsertAt(&Teks, Uji1, Panjang/2);
        Teks.Neff ++;
    }
    MakeTabWord(&Salinan);
    CopyTabWord(Salinan);
    Get(Teks, Panjang/2);
    DeleteFirst(&Teks);
    GetCapacity(Teks);
    DeleteAt(&Teks, Panjang/2);
    for (int i = 0; i<Panjang; i++){
        DeleteLast(&Teks);
    }
    ElType Uji2 = toWord("Selipan");
    SearchTabWord(Salinan, Uji2);
    DeallocateTabWord(&Teks);

    return 0;
}
