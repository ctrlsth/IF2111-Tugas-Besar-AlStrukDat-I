#include "load.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void LOAD(char * filename, ArrayDin *arraygame){
    int n = 0;
    int i,j;
    int length = 0;
    int count = 0;
    char huruf;
    ElType kata;
    while(arraygame->Neff > 0){
        DeleteLast(arraygame);
    }
    C_STARTKATA(filename);
    if (!EndKata){
        n = KataInt(CKata);
        C_ADVKATA();
        for(i=0;i<n;i++){
            kata = toEltype(CKata);
            InsertLast(arraygame,kata);
            C_ADVKATA();
        }
    }
}