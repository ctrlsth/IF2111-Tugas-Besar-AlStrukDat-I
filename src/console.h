#ifndef __CONSOLE__H__
#define __CONSOLE__H__

#include <stdio.h>
#include "boolean.h"
#include "ADT/mesinkata.h"
#include "ADT/queue.h"
#include "ADT/array.h"
#include "ADT/stack.h"
#include "ADT/set.h"
#include "ADT/map.h"

void delay(int milli_seconds);
/* Memberikan delay pada program selama (lamaDelay * 1/100) detik */

void printDelay(char *daString, int lamaDelay);
/* Menampilkan output secara perlahan */

void START(char *inputCommand, TabWord *listGame, boolean *loaded);

void LOAD(char *filename, TabWord *listGame, boolean *loaded, Stack *stackHistory, ListOfSet *listPlayer, ListOfMap *scoreBoard);

void HELP(boolean loaded);

void LISTGAME(TabWord listGame);

void CREATEGAME(TabWord *listGame, ListOfSet *listPlayers, ListOfMap *scoreBoard);

void DELETEGAME(TabWord *listGame, Queue queueGame, ListOfMap *scoreBoard, ListOfSet *listPlayers, Stack *stackHistory);

void QUEUEGAME(TabWord listGame, Queue *queueGame);

void PLAYGAME(TabWord listGame, Queue *queueGame, ListOfMap *scoreBoard, ListOfSet *listPlayer, Stack *stackHistory);

void SKIPGAME(TabWord listGame, Queue *queueGame, ListOfMap *scoreBoard, ListOfSet *listPlayer, Stack *stackHistory, int num);

void SAVE(char *filename, TabWord listGame, Stack stackHistory, ListOfMap scoreBoard);

void QUIT(TabWord listGame, Stack stackHistory, ListOfMap scoreBoard);

void SCOREBOARD(ListOfSet listPlayer, ListOfMap scoreBoard, TabWord listGame);

void UPDATESB(int score, Set *gamePlayers, Map *playerScores, int whatGame);

void RESETSB(ListOfSet *listPlayer, ListOfMap *scoreBoard, TabWord listGame);

void SHOWHISTORY(Stack stackHistory, int num);

void RESETHISTORY(Stack *stackHistory);

void UPDATEHISTORY(Stack *stackHistory, Word gameName);

#endif