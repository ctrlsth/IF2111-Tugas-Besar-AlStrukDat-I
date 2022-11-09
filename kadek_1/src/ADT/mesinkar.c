/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>
#include <stdlib.h>

char CC;
boolean EOP;

static FILE *pita;
static FILE *config;
static int retval;

void START()
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pita = stdin;
    ADV();
}
void ADV()
{
    /* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    retval = fscanf(pita, "%c", &CC);
    EOP = (CC == EOF);
    if (EOP)
    {
        // printf("close pita\n");
        fclose(pita);
    }
}

/*###### Config Start ######*/
void C_START(char *c, boolean *fileopen)
{
    config = fopen(c, "r");
    if (config == NULL){
        *fileopen = false;
    }
    else{
        *fileopen = true;
        C_ADV();
    }
}

void C_ADV()
{
    /* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */
    /* Algoritma */

    CC = fgetc(config);
    //eop = (cc == MARK);
    if (CC == EOF) {
        fclose(config);
    }
    // retval = fscanf(config, "%c", &CC);
    // EOP = (retval == EOF);
    // if (EOP)
    // {
    //     // CC = MARK;
    //     fclose(config);
    // }
}
/*###### Config End ######*/