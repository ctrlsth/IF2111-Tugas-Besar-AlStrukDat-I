#include "../mesinkarakter.h"


int main(){
    cmdstart();
    boolean loaded;
    printf("%c\n",CC);
    loadstart("./data/config.txt",&loaded);
    printf("%c\n",CC);
}
