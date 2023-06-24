#include <stdio.h>
#include <stdlib.h>

//не работает из-за не константности размера SSS

#define EMPTY 0 // значение пустой клетки
#define VISITED -1 // значение посещенной клетки

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int size_x;
    int size_y;
} BRD;

void printBoard(BRD* SSS, int board[*SSS->size_x][*SSS->size_y]) {
    for (int i = 0; i < SSS->size_x; i++) {
        for (int j = 0; j < SSS->size_y; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void boardConstructor(BRD* SSS, int board[SSS->size_x][SSS->size_y]) {
    for (int i = 0; i < SSS->size_x; i++) {
        for (int j = 0; j < SSS->size_y; j++) {
            board[i][j] = EMPTY;
        }
    }
}

int isValid(BRD* SSS, int x, int y) {
    return (((x >= 0) && (x < SSS->size_x))
        && ((y >= 0) && (y < SSS->size_y)));
}

void printReadyWayInLine(BRD* SSS, int board[SSS->size_x][SSS->size_y]) {
    int counter = 1;
    while (counter < SSS->size_x * SSS->size_y) {
        int iterationCounter = 0;
        for (int i = 0; i < SSS->size_x; i++) {
            for (int j = 0; j < SSS->size_y; j++) {
                if (board[i][j] == counter) {
                    printf("(%d,%d) ", j, i);
                    counter++;
                    iterationCounter = 0;
                }
            }
        }
        iterationCounter++;
        if (iterationCounter == 2)
            break;
    }
}

int countMoves(BRD* SSS, int board[SSS->size_x][SSS->size_y], Point p) {
    int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[] = { 1, 2,  2,  1, -1, -2,-2,-1 };
    int count = 0;

    for (int i = 0; i < 8; i++) {
        int x = p.x + dx[i];
        int y = p.y + dy[i];
        if (isValid(SSS, x, y)) {
            if (board[x][y] == EMPTY) {
                count++;
            }
        }
    }
    return count;
}

Point nextMove(BRD* SSS, int board[SSS->size_x][SSS->size_y], Point p) {
    int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    Point next = { -1, -1 };
    int minMoves = SSS->size_x + 1; //check

    for (int i = 0; i < 8; i++) {
        int x = p.x + dx[i];
        int y = p.y + dy[i];
        if (isValid(SSS, x, y)) {
            if (board[x][y] == EMPTY) {
                int moves = countMoves(SSS, board, (Point) { x, y });
                if (moves < minMoves) {
                    minMoves = moves;
                    next.x = x;
                    next.y = y;
                }
            }
        }
    }
    return next;
}

void knightTour(BRD* SSS, int board[SSS->size_x][SSS->size_y], Point start) {
    Point current = start;
    int step = 1;
    board[current.x][current.y] = step;
    while (step < SSS->size_x * SSS->size_y) {
        current = nextMove(SSS, board, current);
        if (current.x == -1 && current.y == -1) {
            printf("No solutions.\n");
            return;
        }
        step++;
        board[current.x][current.y] = step;
    }
    printBoard(SSS, board);
    printf("\n");
    printReadyWayInLine(SSS, board);
}

int main() {
    BRD* SSS = malloc(sizeof(int));
    int sizeOfBoardX;
    int sizeofBoardY;
    scanf("%d %d", &sizeOfBoardX, &sizeofBoardY);
    SSS->size_x = sizeOfBoardX;
    SSS->size_y = sizeofBoardY;
    int board[SSS->size_x][SSS->size_y];
    boardConstructor(SSS, board);

    Point start = { 0, 0 };
    knightTour(SSS, board, start);

    return 0;
}