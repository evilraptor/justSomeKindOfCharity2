#pragma once
#include <stdio.h>
#include <stdlib.h>
#define BOARDSIZE 8 //размерность доски
#define EMPTY 0 // значение пустой клетки
#define VISITED -1 // значение посещенной клетки

typedef struct {
    int x;
    int y;
} Point; //структура для хранения координат клетки

void printBoard(int board[BOARDSIZE][BOARDSIZE]); //вывод доски на экран
void boardConstructor(int board[BOARDSIZE][BOARDSIZE]); //определение доски
int isValid(int x, int y); //проверка что клетка находится в пределах доски
void printReadyWayInLine(int board[BOARDSIZE][BOARDSIZE]); //вывод последовательности ходов строкой

int countMoves(int board[BOARDSIZE][BOARDSIZE], Point p); //нахождение количества доступных ходов из точки
Point nextMove(int board[BOARDSIZE][BOARDSIZE], Point p); // функция для нахождения следующей позиции коня
void knightTour(int board[BOARDSIZE][BOARDSIZE], Point start); // функция для нахождения последовательности ходов коня
