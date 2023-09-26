#include "../Headers/game_of_life.h"

void display(int **grid) {
    gotoxy(0, 0);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? 'O' : ' ');
        }
        printf("\n");
    }
}