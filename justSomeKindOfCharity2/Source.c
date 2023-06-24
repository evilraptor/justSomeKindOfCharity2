#include "Header.h"

int main() {
	int board[BOARDHEIGHT][BOARDWIDTH];
	boardConstructor(board);

	Point start = { 0, 0 };
	knightTour(board, start);

	return 0;
}