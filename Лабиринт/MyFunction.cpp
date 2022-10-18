#include "Header.h"
#include "MyFunction.h"

void SetColor(int pnColortext , int pnColorbackground) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((pnColorbackground << 4) | pnColortext));
}

void SetCursor(int pnRow, int pnCol) {
	COORD position;
	HANDLE hConsole;

	position.Y = pnRow;
	position.X = pnCol;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}