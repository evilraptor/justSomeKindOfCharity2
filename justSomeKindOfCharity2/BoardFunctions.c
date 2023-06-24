#include "Header.h"

void printBoard(int board[BOARDHEIGHT][BOARDWIDTH]) {
    for (int i = 0; i < BOARDHEIGHT; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void boardConstructor(int board[BOARDHEIGHT][BOARDWIDTH]) {
    for (int i = 0; i < BOARDHEIGHT; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {
            board[i][j] = EMPTY;
        }
    }
}

int isValid(int x, int y) {
	return (((x >= 0) && (x < BOARDHEIGHT))
        && ((y >= 0) && (y < BOARDWIDTH)));
}

void printReadyWayInLine(int board[BOARDHEIGHT][BOARDWIDTH]) {
    int counter = 1;
    while (counter < BOARDHEIGHT * BOARDWIDTH) {
        int iterationÑounter = 0;
        for (int i = 0; i < BOARDHEIGHT; i++) {
            for (int j = 0; j < BOARDWIDTH; j++) {
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