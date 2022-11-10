#ifndef __CONSOLE__
#define __CONSOLE__

#include "../src/ADT/mesinkata.h"
#include "../src/ADT/array.h"
#include "../src/ADT/queue.h"

void delay(int milli_seconds);

void printDelay(char *daString, int lamaDelay);

void start(char * inputcommand, ArrayDin *arrayGame, boolean *fileopen);

void LOAD(char * filename, ArrayDin *arrayGame, boolean *fileopen);

void help(boolean mainmenu);

void CREATEGAME(ArrayDin *listgame);

void QUEUEGAME(ArrayDin listgame, Queue* queuegame);

void LISTGAME(ArrayDin listgame);

void PLAYGAME(Queue* queuegame);

void SKIPGAME(Queue* queuegame, int num);

void DELETEGAME(ArrayDin *listgame, Queue queuegame);

void SAVE(Kata file, ArrayDin listGame);

void QUIT(ArrayDin listGame);

#endif