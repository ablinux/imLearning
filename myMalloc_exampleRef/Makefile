TARGET := myMalloc

all:myMalloc

myMalloc:main.o myMalloc.o
	gcc -Wall main.o myMalloc.o

main.o:main.c
	gcc -c main.c -I myMalloc.h

myMalloc.o:myMalloc.c
	gcc -c myMalloc.c -I myMalloc.h