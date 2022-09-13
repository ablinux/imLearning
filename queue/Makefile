TARGET := test

all:test

test:test.o queue.o
	gcc -Wall test.o queue.o

main.o:main.c
	gcc -c test.c -I queue.h

queue.o:queue.c
	gcc -c queue.c -I queue.h