#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define ROWS 25
#define COLS 80

void initialize(int **grid, FILE *fptr);
void display(int **grid);
void update(int **grid);
void memoryCleaner(int **grid);
void gotoxy(int x, int y);
int menu(int **grid);

int main() {
    int speed, scan;
    char scanChar;
    int **grid = (int **)malloc(ROWS * sizeof(int *));
    
    if(menu(grid) != 1){
        printf("Please, set the speed of steps: ");
        scan = (scanf("%d%c", &speed, &scanChar));
        if (scan == 2 && scanChar == '\n' && (speed > 0 && speed <= 1000)) {
            while (!kbhit()) {
                display(grid);
                update(grid);
                Sleep(speed);
            }
        } else {
            printf("Please, set the correct positive number.");
        }
        memoryCleaner(grid);
    } else {
        printf("n/a\n");
    }
    return 0;
}

void initialize(int **grid, FILE *fptr) {
    char symbol;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            symbol = fgetc(fptr);
            if (symbol != '\0' && symbol != '\n' && symbol != ' ') {
                grid[i][j] = symbol - 48;
            }
        }
    }
}

void display(int **grid) {
    gotoxy(0, 0);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? 'O' : ' ');
        }
        printf("\n");
    }
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

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

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