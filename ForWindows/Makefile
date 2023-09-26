CFLAGS = -Wall -Werror -Wextra
CC = gcc
HEAD = Headers
PROP = Properties
GAME = Game_Of_Life
SOURCES = game_of_life.o display.o gotoxy.o initialize.o memoryCleaner.o menu.o update.o

all: game

game: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o out/game

game_of_life.o: $(GAME)/game_of_life.c $(HEAD)/game_of_life.h
	$(CC) $(CFLAGS) -c $(GAME)/game_of_life.c

display.o: $(PROP)/display.c  $(HEAD)/game_of_life.h
	$(CC) $(CFLAGS) -c $(PROP)/display.c

gotoxy.o: $(PROP)/gotoxy.c  $(HEAD)/game_of_life.h
	$(CC) $(CFLAGS) -c $(PROP)/gotoxy.c

initialize.o: $(PROP)/initialize.c  $(HEAD)/game_of_life.h
	$(CC) $(CFLAGS) -c $(PROP)/initialize.c

memoryCleaner.o: $(PROP)/memoryCleaner.c  $(HEAD)/game_of_life.h
	$(CC) $(CFLAGS) -c $(PROP)/memoryCleaner.c

menu.o: $(PROP)/menu.c  $(HEAD)/game_of_life.h
	$(CC) $(CFLAGS) -c $(PROP)/menu.c

update.o: $(PROP)/update.c  $(HEAD)/game_of_life.h
	$(CC) $(CFLAGS) -c $(PROP)/update.c
	
clean:
	rm *.o