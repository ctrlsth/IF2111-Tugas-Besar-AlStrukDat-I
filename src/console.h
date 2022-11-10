#ifndef __CONSOLE__H__
#define __CONSOLE__H__

#include <stdio.h>
#include "boolean.h"
#include "ADT/mesinkata.h"
#include "ADT/array.h"

void delay_hundredth_sec(int lamaDelay);
/* Memberikan delay pada program selama (lamaDelay * 1/100) detik */

void printDelay(char *daString);
/* Menampilkan output secara perlahan */

void START(char *inputCommand, TabWord *listGame, boolean *loaded);

void LOAD(char *filename, TabWord *listGame, boolean *loaded);

void HELP(boolean loaded);

void LISTGAME(TabWord listGame);

void CREATEGAME(TabWord *listGame);

void DELETEGAME(TabWord *listGame);

void SAVE(char* filename, TabWord listGame);

void QUIT(TabWord listGame);

#endif