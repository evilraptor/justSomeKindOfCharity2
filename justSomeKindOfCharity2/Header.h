#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define BOARDSIZE 8 //размерность доски
#define EMPTY 0 // значение пустой клетки
#define VISITED -1 // значение посещенной клетки
#define BOARDWIDTH 9
#define BOARDHEIGHT 9

typedef struct {
    int x;
    int y;
} Point; //структура для хранения координат клетки

void printBoard(int board[BOARDHEIGHT][BOARDWIDTH]); //вывод доски на экран
void boardConstructor(int board[BOARDHEIGHT][BOARDWIDTH]); //определение доски
int isValid(int x, int y); //проверка что клетка находится в пределах доски
void printReadyWayInLine(int board[BOARDHEIGHT][BOARDWIDTH]); //вывод последовательности ходов строкой

int countMoves(int board[BOARDHEIGHT][BOARDWIDTH], Point p); //нахождение количества доступных ходов из точки
Point nextMove(int board[BOARDHEIGHT][BOARDWIDTH], Point p); // функция для нахождения следующей позиции коня
void knightTour(int board[BOARDHEIGHT][BOARDWIDTH], Point start); // функция для нахождения последовательности ходов коня
