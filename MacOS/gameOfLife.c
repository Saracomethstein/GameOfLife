#include "headers/gameOfLife.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        int **grid = NULL;
        int* arr;
        char* file = (char*)malloc(sizeof(char) * 1024);

        grid = memoryAllocate(grid);
        arr = printMenu();
        int map = arr[0], speed = arr[1];

        file = mapSelect(map, file);
        FILE *fptr = fopen(file, "rt");
        if (fptr == NULL) {
            printf("Your selected path is incorrect. Please, set the correct path.");
            return -1;
        }
        initialize(grid, fptr);
        displayGrid(speed, grid);
        memoryCleaner(grid);
        if (map == 5)
            free(file);
        fclose(fptr);
    } else {
        printf("\033[0;31m");
        printf("Sorry, we didn't find such file...");
    }
    return 0;
}