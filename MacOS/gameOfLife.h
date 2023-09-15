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
void display(int **grid, int n);
void update(int **grid);
void memoryCleaner(int **grid);

#endif GAME_OF_LIFE_H