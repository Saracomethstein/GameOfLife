#include "../Headers/game_of_life.h"

void memoryCleaner(int **grid) {
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);
}