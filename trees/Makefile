TARGET := TREE

all:TARGET


TARGET:main.o queue.o stackLL.o
	gcc -Wall -g main.o queue.o stackLL.o

main.o:main.c
	gcc -c  main.c

queue.o: queue.c
	gcc -c  queue.c

stackLL.o: stackLL.c
	gcc -c stackLL.c

clean:
	rm *.o