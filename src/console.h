#ifndef __CONSOLE__H__
#define __CONSOLE__H__

#include <stdio.h>
#include "boolean.h"
#include "ADT/mesinkata.h"
#include "ADT/array.h"

boolean SAVE(Word filename, ArrayDin listgame, ArrayDin listhistory);

// void QUIT(ArrayDin listgame, ArrayDin listhistory);

void LOAD(char * filename, ArrayDin *arraygame);

// boolean compareStr()

#endif