#include <stdio.h>
#include "mesinkarakter.h"

/* State Mesin */
char CC;        // CC   : Current Character         = Karakter yang sedang dibaca
boolean EOP;    // EOP  : End Of Process / Pita     = Ditemukan MARK pada pita
boolean EOPC;   // EOPC : End Of Process Command    = Ditemukan MARKCMD pada pita

static FILE *pita;
static int retval;

void START()
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
{
    pita = stdin;
    ADV();
}

void ADV()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita, "%c", &CC);
    EOP = (CC == MARK);
    if (EOP)
    {
        fclose(pita);
    }
}

void STARTC()
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
{
    pita = stdin;
    ADVC();
}

void ADVC()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita, "%c", &CC);
    EOPC = (CC == MARKCMD);
    if (EOPC)
    {
        fclose(pita);
    }
}

char GetCC()
/* Mengirimkan CC */
{
    return CC;
}

boolean IsEOP()
/* Mengirimkan true jika CC = MARK */
{
    return (CC == MARK);
}
