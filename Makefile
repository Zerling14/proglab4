all: main.c
	gcc -Wall -o main main.c -lm
	gcc -Wall -S main.c
