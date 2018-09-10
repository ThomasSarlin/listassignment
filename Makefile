CC = gcc

CFLAGS = -std=gnu11 -Wall -Wmissing-declarations -Wreturn-type -Wparentheses -Wunused -Wold-style-definition -Wundef -Wshadow -Wstrict-prototypes -Wswitch-default -Wunreachable-code

SOURCES = mpasswdsort.c userInfo.c linkedList.c
TARGET = mpasswdsort

all:
		$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)
all33:
	gcc mpasswdsort.c userInfo.c linkedList.c  -Wall -g -o mpasswdsort


