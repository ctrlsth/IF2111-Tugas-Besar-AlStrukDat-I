#include <stdio.h>
#include "mesinkarakter.h"

/* State Mesin */
char CC;        // CC   : Current Character
boolean EOP;    // EOP  : End Of Process / Pita

static FILE *pita;
static FILE *load;
static int retval;

void loadstart(char* txtfile)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
{
    load = fopen(txtfile, "r");
    ADV(true);
}

void cmdstart()
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
{
    pita = stdin;
    ADV(false);
}

void adv(boolean loadtxt)
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */
{
	if (loadtxt)
	{
		retval = fscanf(pita, "%c", &CC);
	}
	else
	{
		retval = fscanf(pita, "%c", &CC);
	}
	EOP = (CC == EOF);
	if (EOP)
	{
		fclose(pita);
	}
}
