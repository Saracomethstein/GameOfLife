#include "../Headers/game_of_life.h"

int menu(int **grid){
    char *FileName;
    int chose, scan;
    int flag = 1;
    char scanChar;

    printf("(1) Pulsar.\n(2) Blinker.\n(3) Spaceship.\n(4) Gun.\nChose map (1-4): ");
    scan = (scanf("%d%c", &chose, &scanChar));
    if(scan == 2 && scanChar == '\n' && chose > 0 && chose < 5){
        if (chose == 1){
            FileName = "../Maps/pulsar.txt";
        } else if (chose == 2) {
            FileName = "../Maps/blinker.txt";
        } else if (chose == 3) {
            FileName = "../Maps/spaceship.txt";
        } else if (chose == 4) {
            FileName = "../Maps/gun.txt";
        }

        FILE *fptr = fopen(FileName, "rt");

        for (int i = 0; i < ROWS; i++) {
            grid[i] = (int *)malloc(COLS * sizeof(int));
        }
        initialize(grid, fptr);
        flag = 0;
    } else {
        flag = 1;
    }

    return flag;
}