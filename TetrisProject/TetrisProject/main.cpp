#include <stdio.h>
#include <Windows.h>

#define BOARDWIDTH 10
#define BOARDHEIGHT 20

enum { EMPTY, BRICK, WALL };
const char* arTile[3] = { ". ","■","□" };
int board[BOARDWIDTH+2][BOARDHEIGHT+2];

void boardDraw();
void gotoxy(int x,int y);
void initBoard();

void main() {
	initBoard();
	boardDraw();
}

void initBoard() {
	for (int x = 0; x < BOARDWIDTH + 2; x++) {
		for (int y = 0; y < BOARDHEIGHT + 2; y++) {
			board[x][y] = (y == 0 || x == 0 || y == BOARDHEIGHT + 1 || x == BOARDWIDTH + 1) ? WALL : EMPTY;
		}
	}
}

void boardDraw() {
	for (int x = 0; x < BOARDWIDTH + 2; x++) {
		for (int y = 0; y < BOARDHEIGHT + 2; y++) {
			gotoxy(x*2, y); // Y가 크기가 더 커서 x에 *2를 넣어주네요 
			printf(arTile[board[x][y]]);
		}
	}
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}