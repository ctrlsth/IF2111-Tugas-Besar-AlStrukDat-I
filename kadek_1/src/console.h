#ifndef __START__
#define __START__

#include "../src/ADT/mesinkata.h"
#include "../src/ADT/array.h"
#include "../src/ADT/queue.h"

void start(char * inputcommand, ArrayDin *arrayGame, boolean *fileopen);

void LOAD(char * filename, ArrayDin *arrayGame, boolean *fileopen);

void help(boolean mainmenu);

void QUEUEGAME(ArrayDin listgame, Queue* queuegame);

void PLAYGAME(Queue* queuegame);

void SKIPGAME(Queue* queuegame, int num);

#endif