#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

//          INCLUDE LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//          SIZE OF GAME FIELD
#define ROWS 25
#define COLS 80

void initialize(int **grid, FILE *fptr);
void display(int speed, int **grid);
void update(int **grid);
void memoryCleaner(int **grid);
int **memoryAllocate(int **grid);

void displayGrid(int speed, int **grid);
int* printMenu();
char *mapSelect(int map, char *file);

#endif