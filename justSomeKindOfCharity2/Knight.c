#include "Header.h"

int countMoves(int board[BOARDHEIGHT][BOARDWIDTH], Point p) {
    //FIXME ������������ ����
    /*
    * ����� 8 � ������� dx,dy �������� ��������������� 
        ��������� ��������� ����� ����
      (*��� ������������* ���������� �������� ����� �� �����
        � ���� ������ �������)
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

Point nextMove(int board[BOARDHEIGHT][BOARDWIDTH], Point p) {
    int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    Point next = { -1, -1 };
    int minMoves = min(BOARDHEIGHT,BOARDWIDTH) + 1;

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

void knightTour(int board[BOARDHEIGHT][BOARDWIDTH], Point start) {
    Point current = start;
    int step = 1;
    board[current.x][current.y] = step;
    while (step < BOARDHEIGHT * BOARDWIDTH) {
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