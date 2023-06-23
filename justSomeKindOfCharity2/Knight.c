#include "Header.h"

int countMoves(int board[BOARDSIZE][BOARDSIZE], Point p) {
    //FIXME пересмотреть шаги
    /*
    * всего 8 и массивы dx,dy означают соответствующие 
        изменение координат после хода
      (*для перепроверки* посмотреть картинку ходов из инета
        и идти против часовой)
    */
    int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[] = { 1, 2,  2,  1, -1, -2,-2,-1 };
    int count = 0;

    for (int i = 0; i < 8; i++) {
        int x = p.x + dx[i];
        int y = p.y + dy[i];
        if (isValid(x, y)) {
            if (board[x][y] == EMPTY) {
                count++;
            }
        }
    }
    return count;
}

Point nextMove(int board[BOARDSIZE][BOARDSIZE], Point p) {
    int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    Point next = { -1, -1 };
    int minMoves = BOARDSIZE + 1;

    for (int i = 0; i < 8; i++) {
        int x = p.x + dx[i];
        int y = p.y + dy[i];
        if (isValid(x, y)) {
            if (board[x][y] == EMPTY) {
                int moves = countMoves(board, (Point) { x, y });
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

void knightTour(int board[BOARDSIZE][BOARDSIZE], Point start) {
    Point current = start;
    int step = 1;
    board[current.x][current.y] = step;
    while (step < BOARDSIZE * BOARDSIZE) {
        current = nextMove(board, current);
        if (current.x == -1 && current.y == -1) {
            printf("No solutions.\n");
            return;
        }
        step++;
        board[current.x][current.y] = step;
    }
    printBoard(board);
    printf("\n");
    printReadyWayInLine(board);
}