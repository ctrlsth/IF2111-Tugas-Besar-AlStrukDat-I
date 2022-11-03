#ifndef __MESIN_KAR__
#define __MESIN_KAR__

#include "boolean.h"

#define MARK '.'

/* State Mesin */
extern char CC;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca. 
   I.S. : sembarang
   F.S. : cc adalah karakter pertama pada pita
          Jika cc != MARK maka eop bernilai false 
          Jika cc = MARK maka eop bernilai true */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = cc, cc != MARK 
   F.S. : cc adalah karakter berikutnya dari cc yang lama,
          cc mungkin = MARK
          Jika cc = MARK maka eop bernilai true */

#endif