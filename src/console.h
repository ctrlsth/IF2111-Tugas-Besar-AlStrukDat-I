#ifndef __CONSOLE__H__
#define __CONSOLE__H__

#include <stdio.h>
#include "boolean.h"
#include "ADT/mesinkata.h"
#include "ADT/array.h"

boolean SAVE(Word filename, TabWord listgame, TabWord listhistory);

void QUIT(TabWord listgame, TabWord listhistory);

#endif