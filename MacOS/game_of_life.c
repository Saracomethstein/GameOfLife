#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 25
#define COLS 80

void initialize(int **grid, FILE *fptr);
void display(int **grid, int n);
void update(int **grid);
void memoryCleaner(int **grid);

int main(int argc, char *argv[]) {
    if ((argc >= 2 && fopen(argv[1], "rt"))) {
        int n;
        char c;
        int **grid = (int **)malloc(ROWS * sizeof(int *));

        FILE *fptr = fopen(argv[1], "rt");

        for (int i = 0; i < ROWS; i++) {
            grid[i] = (int *)malloc(COLS * sizeof(int));
        }

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

    } else {
        printf("Sorry, we didn't find such file...");
    }

    return 0;
}

void initialize(int **grid, FILE *fptr) {
    char symbol;

    for (int i = 0; i < ROWS; i++) {
        for (int j = -1; j < COLS; j++) {
            symbol = fgetc(fptr);
            if (symbol != '\0' && symbol != '\n' && symbol != ' ') {
                grid[i][j] = symbol - 48;
            }
        }
    }
}

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

void update(int **grid) {
    int newGrid[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;

                    int ni = (i + dx + ROWS) % ROWS;
                    int nj = (j + dy + COLS) % COLS;

                    if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS) {
                        neighbors += grid[ni][nj];
                    }
                }
            }

            if (grid[i][j]) {
                newGrid[i][j] = (neighbors == 2 || neighbors == 3);
            } else {
                newGrid[i][j] = (neighbors == 3);
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

void memoryCleaner(int **grid) {
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);
}
