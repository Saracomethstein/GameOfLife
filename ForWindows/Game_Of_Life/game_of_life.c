#include "../Headers/game_of_life.h"

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