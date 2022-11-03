#ifndef __MESIN_KAR__
#define __MESIN_KAR__

#include "../boolean.h"

#define MARK '.'
#define MARKCMD '\n'

/* State Mesin */
extern char CC;
extern boolean EOP;
extern boolean EOPC;

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

void STARTC();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARKCMD maka EOP akan padam (false)
          Jika CC = MARKCMD maka EOP akan menyala (true) */

void ADVC();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARKCMD
          Jika  CC = MARKCMD maka EOP akan menyala (true) */

char GetCC();
/* Mengirimkan CC */

boolean IsEOP();
/* Mengirimkan true jika CC = MARK */

#endif