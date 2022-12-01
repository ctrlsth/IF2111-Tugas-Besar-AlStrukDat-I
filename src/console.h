#ifndef __CONSOLE__H__
#define __CONSOLE__H__

#include <stdio.h>
#include "boolean.h"
#include "ADT/mesinkata.h"
#include "ADT/array.h"

<<<<<<< Updated upstream
boolean SAVE(Word filename, ArrayDin listgame, ArrayDin listhistory);
=======


void delay(int milli_seconds);
/* Memberikan delay pada program selama (lamaDelay * 1/100) detik */
>>>>>>> Stashed changes

// void QUIT(ArrayDin listgame, ArrayDin listhistory);

void LOAD(char * filename, ArrayDin *arraygame);

// boolean compareStr()

#endif