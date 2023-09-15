#include "gameOfLife.h"

int main(int argc, char *argv[]) {
    if ((argc >= 2 && fopen(argv[1], "rt"))) {
        int n;
        char c;
        int **grid;
        FILE *fptr = fopen(argv[1], "rt");

        mem_allocate(grid);
        initialize(grid, fptr);

        printf("Please, set the speed of steps: ");
        if (scanf("%d%c", &n, &c) == 2 && c == '\n' && (n > 0 && n <= 1000)) {
            while (1) {
                display(grid, n);
                update(grid);
            }
        } else {
            printf("Please, set the correct positive number.");
        }

        memoryCleaner(grid);
        fclose(fptr);
    } else {
        printf("Sorry, we didn't find such file...");
    }
    return 0;
}
