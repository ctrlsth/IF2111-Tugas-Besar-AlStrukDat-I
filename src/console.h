#ifndef __CONSOLE__H__
#define __CONSOLE__H__

#include <stdio.h>
#include "boolean.h"
#include "ADT/mesinkata.h"
#include "ADT/queue.h"
#include "ADT/array.h"
#include "ADT/stack.h"

void delay(int milli_seconds);
/* Memberikan delay pada program selama (lamaDelay * 1/100) detik */

void printDelay(char *daString, int lamaDelay);
/* Menampilkan output secara perlahan */

void START(char *inputCommand, TabWord *listGame, boolean *loaded);

void LOAD(char *filename, TabWord *listGame, boolean *loaded);

void HELP(boolean loaded);

void LISTGAME(TabWord listGame);

void CREATEGAME(TabWord *listGame);

void DELETEGAME(TabWord *listGame, Queue queueGame);

void QUEUEGAME(TabWord listGame, Queue *queueGame);

void PLAYGAME(TabWord listGame, Queue *queueGame);

void SKIPGAME(TabWord listGame, Queue *queueGame, int num);

void SAVE(char *filename, TabWord listGame);

void QUIT(TabWord listGame);

#endif