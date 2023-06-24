#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define BOARDSIZE 8 //����������� �����
#define EMPTY 0 // �������� ������ ������
#define VISITED -1 // �������� ���������� ������
#define BOARDWIDTH 9
#define BOARDHEIGHT 9

typedef struct {
    int x;
    int y;
} Point; //��������� ��� �������� ��������� ������

void printBoard(int board[BOARDHEIGHT][BOARDWIDTH]); //����� ����� �� �����
void boardConstructor(int board[BOARDHEIGHT][BOARDWIDTH]); //����������� �����
int isValid(int x, int y); //�������� ��� ������ ��������� � �������� �����
void printReadyWayInLine(int board[BOARDHEIGHT][BOARDWIDTH]); //����� ������������������ ����� �������

int countMoves(int board[BOARDHEIGHT][BOARDWIDTH], Point p); //���������� ���������� ��������� ����� �� �����
Point nextMove(int board[BOARDHEIGHT][BOARDWIDTH], Point p); // ������� ��� ���������� ��������� ������� ����
void knightTour(int board[BOARDHEIGHT][BOARDWIDTH], Point start); // ������� ��� ���������� ������������������ ����� ����
