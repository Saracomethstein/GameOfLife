#include "../headers/gameOfLife.h"

void display(int speed, int **grid) {
    system("clear");
    printf("\033[0;32m");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? '0' : ' ');
        }
        printf("\n");
    }
    usleep(speed * 1000);
}