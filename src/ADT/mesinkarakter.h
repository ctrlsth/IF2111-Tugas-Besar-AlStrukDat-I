#ifndef __MESIN_KAR__
#define __MESIN_KAR__

#include <stdio.h>
#include "../boolean.h"

#define MARK '\n'

/* State Mesin */
extern char CC;
extern boolean EOP;

void loadstart(char* txtfile, boolean *openSuccess);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca. 
   I.S. : sembarang
   F.S. : cc adalah karakter pertama pada pita
          Jika cc != MARK maka eop bernilai false 
          Jika cc = MARK maka eop bernilai true */

void cmdstart();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARKCMD maka EOP akan padam (false)
          Jika CC = MARKCMD maka EOP akan menyala (true) */

void adv(boolean txt);
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = cc, cc != MARK 
   F.S. : cc adalah karakter berikutnya dari cc yang lama,
          cc mungkin = MARK
          Jika cc = MARK maka eop bernilai true */

#endif
