# Belum Kelar

all: main

main: adt.o game.o console.o binomain.o
	gcc binomain.o console.o game.o adt.o -o bnmo

adt.o: mesinkarakter.o mesinkata.o array.o queue.o stack.o map.o set.o
	gcc -o mesinkarakter.o mesinkata.o array.o queue.o stack.o map.o set.o

mesinkarakter.o: mesinkarakter.c mesinkarakter.h
	gcc -c mesinkarakter.c

mesinkata.o: mesinkata.c mesinkata.h mesinkarakter.h
	gcc -c mesinkata.c

array.o: array.c array.h mesinkata.h
	gcc -c array.c

queue.o: queue.c queue.h mesinkata.h
	gcc -c queue.c

stack.o: stack.c stack.h mesinkata.h
	gcc -c stack.c

map.o: map.c map.h mesinkata.h
	gcc -c map.c

set.o: set.c set.h map.h mesinkata.h
	gcc -c set.c

game.o: dinerdash.o hangman.o marvelsnap.o RNG.o
	gcc -o dinerdash.o hangman.o marvelsnap.o RNG.o

dinerdash.o: dinerdash.c dinerdash.h array.h queue.h mesinkata.h
	gcc -c dinerdash.c

hangman.o: hangman.c mesinkata.h
	gcc -c hangman.c

marvelsnap.o: marvelsnap.c marvelsnap.h RNG.h mesinkata.h
	gcc -c marvelsnap.c

RNG.o: RNG.c RNG.h mesinkata.h
	gcc -c RNG.c

console.o: console.c console.h mesinkarakter.h mesinkata.h array.h queue.h stack.h map.h set.h
	gcc -c console.c

binomain.o: binomain.c binomain.h console.h
	gcc -c binomain.c