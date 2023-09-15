#include "gameOfLife.h"

int main(int argc, char *argv[]) {
    if ((argc >= 2 && fopen(argv[1], "rt"))) {
        int **grid;
        FILE *fptr = fopen(argv[1], "rt");

        mem_allocate(grid);
        initialize(grid, fptr);
        displayMenu(grid);
        memoryCleaner(grid);
        fclose(fptr);
    } else {
        printf("Sorry, we didn't find such file...");
    }
    return 0;
}
