#include "Header.h"

void printBoard(int board[BOARDSIZE][BOARDSIZE]) {
    for (int i = 0; i < BOARDSIZE; i++) {
        for (int j = 0; j < BOARDSIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void boardConstructor(int board[BOARDSIZE][BOARDSIZE]) {
    for (int i = 0; i < BOARDSIZE; i++) {
        for (int j = 0; j < BOARDSIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

int isValid(int x, int y) {
	return (((x >= 0) && (x < BOARDSIZE)) 
        && ((y >= 0) && (y < BOARDSIZE)));
}

void printReadyWayInLine(int board[BOARDSIZE][BOARDSIZE]) {
    int counter = 1;
    while (counter < BOARDSIZE * BOARDSIZE) {
        int iterationÑounter = 0;
        for (int i = 0; i < BOARDSIZE; i++) {
            for (int j = 0; j < BOARDSIZE; j++) {
                if (board[i][j] == counter) {
                    printf("(%d,%d) ", j, i);
                    counter++;
                    iterationÑounter = 0;
                }
            }
        }
        iterationÑounter++;
        if (iterationÑounter == 2)
            break;
    }
}