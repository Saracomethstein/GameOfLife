#include "../headers/gameOfLife.h"

int input();

void displayGrid(int speed, int **grid) {
    char symbol;
    while (scanf("%c", &symbol) == 1 && symbol != 'q') {
        display(speed, grid);
        update(grid);
    }
}

int* printMenu() {
    int map;
    int speed;
    printf("\x1b[31m");
    printf("Game ");
    printf("\x1b[32m");
    printf("Of ");
    printf("\x1b[34m");
    printf("Life\n");
    printf("\x1b[0m");

    printf("\x1b[36m");
    printf("Welcome to the Game Of Life!\n");
    printf("We're so thrilled and happy to see you!\n");
    printf("Before we start the Game, here some useful tips:\n");
    printf("\x1b[37m");
    printf("Maps that you can choose:\n");
    printf("(1) Blinker\n");
    printf("(2) Spaceship\n");
    printf("(3) Pulsar\n");
    printf("(4) Gun\n");
    printf("(5) Custom (you should prepare your custom map and type location of it)\n");

    printf("Type the number: ");

    map = input();

    printf("Now choose the speed of updating generations\n(less the number - less the speed)\n");
    printf("Please, set the speed of steps: ");
    speed = input();
    printf("\x1b[32m");
    printf("\nEnjoy the LIFE\n");

    int arr[2] = {map, speed};
    return arr;
}

int input(){
    int input;
    char symbol;
    while (1) {
        if (scanf("%d%c", &input, &symbol) == 2 && (symbol == ' ' || symbol == '\n') && input > 0) {
            break;
        } else {
            printf("Please, set the positive integer number\n");
        }
    }
    return input;
}

char *mapSelect(int map, char *file){
    switch (map) {
        case 1:
            file = "../MacOS/maps/blinker.txt";
            break;
        case 2:
            file = "../MacOS/maps/spaceship.txt";
            break;
        case 3:
            file = "../MacOS/maps/pulsar.txt";
            break;
        case 4:
            file = "../MacOS/maps/gun.txt";
            break;
        case 5:
            printf("Please, write below location of the map, that you want to open:\n");
            scanf("%s", file);
            return file;
        default:
            break;
    }
    return file;
}