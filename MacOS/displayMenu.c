#include "gameOfLife.h"

void displayMenu(int **grid) {
    int n;
    char c;

    printf("Please, set the speed of steps: ");
    if (scanf("%d%c", &n, &c) == 2 && c == '\n' && (n > 0 && n <= 1000)) {
        while (1) {
            display(grid, n);
            update(grid);
        }
    } else {
        printf("Please, set the correct positive number.");
    }
}