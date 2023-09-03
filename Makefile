CC = gcc
CFLAGS = -Wall -Wextra -std=c99
.PHONY: all clean
all: factors rsa
factors: factors.c
	$(CC) $(CFLAGS) -o factors factors.c
rsa: rsa.c
	$(CC) $(CFLAGS) -o rsa rsa.c
clean:
	rm -f factors rsa
