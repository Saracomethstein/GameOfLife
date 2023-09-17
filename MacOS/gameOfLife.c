#include "headers/gameOfLife.h"

int main(int argc, char *argv[]) {
    if ((argc >= 2 && fopen(argv[1], "rt"))) {
        int **grid = NULL;
        FILE *fptr = fopen(argv[1], "rt");

        grid = memoryAllocate(grid);
        initialize(grid, fptr);
        displayMenu(grid);
        memoryCleaner(grid);
        fclose(fptr);
    } else {
        printf("\033[0;31m");
        printf("Sorry, we didn't find such file...");
    }
    return 0;
}