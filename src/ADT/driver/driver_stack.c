#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "array.h"
#include "mesinkata.h"

int main()
{
    Stack yoursussyhistory;
    CreateEmptyStack(&yoursussyhistory); // Membuat stack kosong
    printf("Akan menghasilkan stack yang kosong : \n");
    displayStack(&yoursussyhistory);

    STARTCMD(false);
    Push(&yoursussyhistory, currentCommand); // Menambahkan elemen di stack 
    printf("Setelah di-push element ke dalam history, maka :\n");
    displayStack(&yoursussyhistory);

    printf("Apakah stack full? Tentu saja jawabannya adalah :\n");
    IsStackFull(yoursussyhistory); // Seharusnya mengeluarkan 'false'

    infostack game;
    Pop(&yoursussyhistory, &game); // Mengeluarkan elemen di stack sehingga stack menjadi kosong
    printf("Karena hasilnya adalah stack yang kosong, maka : \n");
    IsStackEmpty(yoursussyhistory); // Seharusnya mengeluarkan 'true'
}

void displayStack(Stack * stack)
{
    Stack * yoursussyhistory;
    int TOP = Top(*yoursussyhistory);
    int i = TOP;
    if (!IsStackEmpty(*yoursussyhistory))
    {
        printf("Berikut history Anda :\n");
        printWord((*yoursussyhistory).T[i]);
        printf("\n");
    }
    else
    {
        printf("Stack kosong. Tidak ada game di history.\n");
    }
    return 0;
}

