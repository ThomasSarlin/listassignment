CC = gcc

CFLAGS = -std=gnu11 -Wall -Wmissing-declarations -Wreturn-type -Wparentheses -Wunused -Wold-style-definition -Wundef -Wshadow -Wstrict-prototypes -Wswitch-default -Wunreachable-code

SOURCES = mpasswdsort.c userInfo.c linkedList.c

TARGET = mpasswdsort

all:
		$(CC) -Wall -g $(SOURCES) -o $(TARGET)

main:mpasswdsort.o userInfo.o linkedList.o
		$(CC) -Wall -g mpasswdsort.o userInfo.o linkedList.o -o $(TARGET)

mpasswdsort.o:mpasswdsort.c mpasswdsort.h
	$(CC) $(CFLAGS) -c mpasswdsort.c

userInfo.o: userInfo.c userInfo.h
	$(CC) $(CFLAGS) -c userInfo.c

linkedList.o:linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c 


all33:
	gcc mpasswdsort.c userInfo.c linkedList.c  -Wall -g -o mpasswdsort


