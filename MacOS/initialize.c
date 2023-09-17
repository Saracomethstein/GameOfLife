#include "headers/gameOfLife.h"

void initialize(int **grid, FILE *fptr) {
    char symbol;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            symbol = (char)fgetc(fptr);
            if (symbol != '\0' && symbol != '\n' && symbol != ' ') {
                grid[i][j] = symbol - 48;
            }
        }
    }
}