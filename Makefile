CC=gcc
NAME=main
CFLAGS= -g -Wall -O3 -std=c11 -o 
SOURCE=USACOSilver.c


main : USACOSilver.c
	$(CC) $(SOURCE) $(CFLAGS) $(NAME)