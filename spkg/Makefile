#!/usr/bin/make -f

CC = g++
SPKG_SRC = spkgGetOpts.cpp spkg.cpp
SPKG_OBJ = spkgGetOpts.o spkg.o
SPKG_CFLAGS = -I. -I../libspkg -L../libspkg -lspkg
SPKG_BINARY = spkg

all : binaries

binaries : $(SPKG_OBJ)
	$(CC) $(SPKG_CFLAGS) -o $(SPKG_BINARY) $(SPKG_OBJ)

clean :
	rm -f *.o $(SPKG_BINARY)
