#include "mesinkata.h"
#include "array.h"
#include <stdio.h>
#include <string.h>

int main(){
    ArrayDin Command;
    int i,j;
    MakeArrayDin(&Command);
    ElType word;
    STARTKATA();
    while(!EndKata){
        word = toEltype(CKata);
        for(j=0;j<word.length;j++){
            printf("%c",word.buffer[j]);
        }
        printf("\n");
        InsertLast(&Command,word);
        ADVKATA();
    }
    for(i=0;i<Command.Neff;i++){
        for(j=0;j<Command.A[i].length;j++){
            printf("%c",Command.A[i].buffer[j]);
        }
        printf("\n");
    }
    DeallocateArrayDin(&Command);
    return 0;
}