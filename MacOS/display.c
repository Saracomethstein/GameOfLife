#include "gameOfLife.h"

void display(int **grid, int n) {
    system("clear");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? 'O' : ' ');
        }
        printf("\n");
    }
    usleep(n * 1000);
}