#include <stdio.h>
#include <stdlib.h>

int strLength(char *kata)
/* Mengembalikan panjang suatu string kata */
{
    int i = 0;
    while (kata[i] != '\0')
    {
        i++;
    }
    return i;
}

char* strConcat(char* s1, char* s2){
    int i,j;
    char* s3;
    s3 = (char*) malloc ((strLength(s1)+strLength(s2)+1) * sizeof(char*));
    for(i=0;i<strLength(s1);i++){
        s3[i] = s1[i];
    }
    for(j=0;j<strLength(s2);j++){
        s3[i] = s2[j];
        i++;
    }
    s3[i] = '\0';
    return s3;
}

int main(){
    char* s1 = "data/";
    char*s2 = "config.txt";
    char* s3;
    s3 = strConcat(s1,s2);
    printf("%s",s3);
    return 0;
}