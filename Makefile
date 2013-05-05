CC=gcc
CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG
PREFIX?=/usr/local

all: 
	mkdir -p bin build
	$(CC) $(CFLAGS) -c src/4241.c -o build/4241.o
	$(CC) $(CFLAGS) src/test4241.c build/4241.o -o bin/test4241