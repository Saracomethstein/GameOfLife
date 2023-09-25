#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define ROWS 25
#define COLS 80

void initialize(int **grid, FILE *fptr);
void display(int **grid);
void update(int **grid);
void memoryCleaner(int **grid);
void gotoxy(int x, int y);
int menu(int **grid);

#endif