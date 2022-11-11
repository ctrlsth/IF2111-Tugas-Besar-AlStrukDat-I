#include "../mesinkata.h"

int main(){
    boolean loaded;
    STARTWORD("./data/config.txt", &loaded);
    while(!EndWord){
        printWord(currentWord);
        printf("\n");
        ADVWORD();
    }
    STARTCMD(true);
    while(!EndWord){
        printWord(currentCommand);
        ADVCMD(true);
    }
}
