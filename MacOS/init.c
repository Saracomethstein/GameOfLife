#include "gameOfLife.h"

void initialize(int **grid, FILE *fptr) {
    char symbol;

    for (int i = 0; i < ROWS; i++) {
        for (int j = -1; j < COLS; j++) {
            symbol = fgetc(fptr);
            if (symbol != '\0' && symbol != '\n' && symbol != ' ') {
                grid[i][j] = symbol - 48;
            }
        }
    }
}