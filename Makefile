# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Target executable
teksako: teksako.c
	$(CC) $(CFLAGS) -o teksako teksako.c
	./teksako

# Clean rule
clean:
	rm -f teksako
