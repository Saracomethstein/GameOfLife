CFLAGS = -Wall -Werror -Wextra
CC = gcc
HEAD = Headers
PROP = Properties
GAME = Game_Of_Life
SOURCES = game_of_life.o display.o gotoxy.o initialize.o memoryCleaner.o menu.o update.o

all: game

game: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o out/game

game_of_life.o: game_of_life.c game_of_life.h
	$(CC) $(CFLAGS) -c game_of_life.c

display.o: display.c game_of_life.h
	$(CC) $(CFLAGS) -c display.c

gotoxy.o: gotoxy.c game_of_life.h
	$(CC) $(CFLAGS) -c gotoxy.c

initialize.o: initialize.c game_of_life.h
	$(CC) $(CFLAGS) -c initialize.c

memoryCleaner.o: memoryCleaner.c game_of_life.h
	$(CC) $(CFLAGS) -c memoryCleaner.c

menu.o: menu.c game_of_life.h
	$(CC) $(CFLAGS) -c menu.c

update.o: update.c game_of_life.h
	$(CC) $(CFLAGS) -c update.c

clear: rm -f *.o