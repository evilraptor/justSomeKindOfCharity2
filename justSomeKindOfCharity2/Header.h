#pragma once
#include <stdio.h>
#include <stdlib.h>
#define BOARDSIZE 8 //����������� �����
#define EMPTY 0 // �������� ������ ������
#define VISITED -1 // �������� ���������� ������

typedef struct {
    int x;
    int y;
} Point; //��������� ��� �������� ��������� ������

void printBoard(int board[BOARDSIZE][BOARDSIZE]); //����� ����� �� �����
void boardConstructor(int board[BOARDSIZE][BOARDSIZE]); //����������� �����
int isValid(int x, int y); //�������� ��� ������ ��������� � �������� �����
void printReadyWayInLine(int board[BOARDSIZE][BOARDSIZE]); //����� ������������������ ����� �������

int countMoves(int board[BOARDSIZE][BOARDSIZE], Point p); //���������� ���������� ��������� ����� �� �����
Point nextMove(int board[BOARDSIZE][BOARDSIZE], Point p); // ������� ��� ���������� ��������� ������� ����
void knightTour(int board[BOARDSIZE][BOARDSIZE], Point start); // ������� ��� ���������� ������������������ ����� ����
