CC=gcc
CFLAGS=-Wall

facepalm: facepalm.c
	$(CC) facepalm.c $(CFLAGS) -o facepalm

clean:
	rm facepalm
