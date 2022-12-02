#include <stdio.h>
#include <stdlib.h>
#include "../array.h"

int main()
{
    TabWord Teks, Salinan;

    printf("MakeTabWord\n");
    MakeTabWord(&Teks);
    int Panjang = Length(Teks);
    if (IsEmpty(Teks))
    {
        printf("IsEmpty: %d\n", IsEmpty(Teks));
        printf("Panjang array efektif : %d", Panjang);
        int i = 0;
        ElType Uji1 = toWord("Sama");
        InsertAt(&Teks, Uji1, 0);
        printf("IsMemberArray Uji1: %d\n", isMemberArray(Teks, Uji1));
        Panjang = Teks.Neff;
        while (i < Panjang)
        {
            printf("InsertLast!\n");
            InsertLast(&Teks, Uji1);
            i++;
        }
        Uji1 = toWord("Selipan");
        printf("InsertAt!\n");
        InsertAt(&Teks, Uji1, Panjang / 2);
        PrintTabWord(Teks);
        Teks.Neff++;
    }
    MakeTabWord(&Salinan);
    printf("CopyTabWord: Salinan!\n");
    CopyTabWord(Salinan);
    PrintTabWord(Salinan);
    printf("Get!\n");
    Get(Teks, Panjang / 2);
    printf("DeleteFirst!\n");
    DeleteFirst(&Teks);
    PrintTabWord(Teks);
    printf("GetCapacity(Teks): %d\n", GetCapacity(Teks));
    printf("DeleteAt!\n");
    DeleteAt(&Teks, Panjang / 2);
    PrintTabWord(Teks);
    for (int i = 0; i < Panjang; i++)
    {
        printf("DeleteAt!: All\n");
        DeleteAt(&Teks, Panjang - 1);
    }
    PrintTabWord(Teks);
    ElType Uji2 = toWord("Selipan");
    printf("Type Word Uji2: 'Selipan'\n");
    printf("SearchTabWord(Salinan, Uji2) = %d\n", SearchTabWord(Salinan, Uji2));
    DeallocateTabWord(&Teks);
    DeallocateTabWord(&Salinan);

    printf("Done\n");

    return 0;
}