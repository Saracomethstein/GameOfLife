#include "headers/gameOfLife.h"

void memoryCleaner(int **grid) {
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);
}

int **memoryAllocate(int **grid){
    grid = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        grid[i] = (int *)malloc(COLS * sizeof(int));
    }
    return grid;
}