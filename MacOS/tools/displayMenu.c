#include "../headers/gameOfLife.h"

void displayMenu(int **grid) {
    int n;
    char c;

    printf("Please, set the speed of steps: ");
    if (scanf("%d%c", &n, &c) == 2 && (c == '\n' || c == ' ')) {
//        display(grid, n);
        while (1) {
            display(grid, n);
            update(grid);
        }
    } else {
        printf("Please, set the correct positive number.");
    }
}