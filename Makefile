CC = gcc

CFLAGS = -std=gnu11 -Wall -Wmissing-declarations -Wreturn-type -Wparentheses -Wunused -Wold-style-definition -Wundef -Wshadow -Wstrict-prototypes -Wswitch-default -Wunreachable-code

SOURCES = mpasswdsort.c userInfo.c linkedList.c

TARGET = mpasswdsort

all:mpasswdsort.o userInfo.o linkedList.o
		$(CC) -Wall mpasswdsort.o userInfo.o linkedList.o -o $(TARGET)

main:mpasswdsort.o userInfo.o linkedList.o
		$(CC) $(CFLAGS) mpasswdsort.o userInfo.o linkedList.o -o $(TARGET)

mpasswdsort.o:mpasswdsort.c mpasswdsort.h
	$(CC) $(CFLAGS) -c mpasswdsort.c

userInfo.o: userInfo.c userInfo.h
	$(CC) $(CFLAGS) -c userInfo.c

linkedList.o:linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c 

