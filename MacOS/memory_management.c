#include "gameOfLife.h"

void memoryCleaner(int **grid) {
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);
}