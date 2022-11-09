#include "../src/ADT/array.h"
#include "../src/console.h"

int main(){
    int i,j;
    ArrayDin listgame;
    MakeArrayDin(&listgame);
    LOAD("config.txt",&listgame);
    printf("list game anda:\n");
    for (i=0;i<listgame.Neff;i++){
        printf("%d. ",i + 1);
        for(j=0;j<listgame.A[i].Length;j++){
            printf("%c",listgame.A[i].TabWord[j]);
        }
            printf("\n");
    }
}