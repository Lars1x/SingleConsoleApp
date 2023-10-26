#include "header.h"
#include "MyFunction.h"

MYUI nBit = 0b10000000000000000000000000000000;
MYUI* nBug;
int nEndCol = 31, nEndRow = 14,     // координаты конца
nBegCol = 2, nBegRow = 0;       // координаты начала
unsigned int nLab[32] = {
				0b11011111111111111111111111111111, //1
				0b11011111111000000000011111101111, //2 
				0b11011111111011111111011111101111, //3
				0b11000000000011111111011111101111, //4
				0b11111011111111111111011111101111, //5
				0b11111011111110111111000000001111, //6
				0b11111011111110111111111011111111, //7
				0b11111011111110111111111011111111, //8
				0b11111011111110000000000011111111, //9
				0b11111011111111111111111011111111, //10
				0b11111011111111111111111011111111, //1
				0b11111011111000000111111011111111, //2
				0b11000011111111110111111011111111, //3
				0b11011111111111110111111011111111, //4
				0b11011111111111110111111011110000, //5
				0b11011111111111110111111011110111, //6
				0b11000000000000000111111011110111, //7
				0b11111111110111110111111011110111, //8
				0b11111111110111110111111011110111, //9
				0b11111111110111110111111011110111, //20
				0b10000111110111110111111011110111, //1
				0b11110111110111110111111011110111, //2
				0b11110111110111110111111000000111, //3
				0b11110111110111110111111111011111, //4
				0b11110000000001110111111111011111, //5
				0b11110111110111110111101111011111, //6
				0b11110111110111110111101111011111, //7
				0b11110111111111110111101111011111, //8
				0b11110000000000000111101111011111, //9
				0b11111111111111111111100000011111, //30
				0b11111111111111111111111111111111, //1
				0b11111111111111111111111111111111 //2
};

int Moving(int pnRow, int pnCol) {
	int nRes;
	SetCursor(pnRow, pnCol*2);
	SetColor(0, 13);
	cout << "  ";
	nBug[pnRow] |= nBit >> pnCol; // запоминание позиции жука

	if (pnRow == nEndRow && pnCol == nEndCol)
		return 1;

	if (pnRow < 31) // шаг вниз
		if (!(nLab[pnRow + 1] & (nBit >> pnCol)))
			if (!(nBug[pnRow + 1] & (nBit >> pnCol))) {
				nRes = Moving(pnRow + 1, pnCol);
				if (nRes)
					return nRes;
			}

	if (pnCol < 31) // шаг вправо
		if (!(nLab[pnRow] & (nBit >> (pnCol + 1))))
			if (!(nBug[pnRow] & (nBit >> (pnCol + 1)))) {
				nRes = Moving(pnRow, pnCol + 1);
				if (nRes)
					return nRes;
			}
	if (pnRow > 0) // шаг вверх
		if (!(nLab[pnRow - 1] & (nBit >> pnCol)))
			if (!(nBug[pnRow - 1] & (nBit >> pnCol))) {
				nRes = Moving(pnRow - 1, pnCol);
				if (nRes)
					return nRes;
			}

	if (pnCol > 0) // шаг влево
		if (!(nLab[pnRow] & (nBit >> (pnCol - 1))))
			if (!(nBug[pnRow] & (nBit >> (pnCol - 1)))) {
				nRes = Moving(pnRow, pnCol - 1);
				if (nRes)
					return nRes;
			}
	SetColor();
	SetCursor(pnRow, pnCol*2);
	cout << "  ";
	return 0;
}
void Labir()
{
	SetConsoleTitle(TEXT("Лабиринт"));
	char sKey = 0;
	int nCol = 2, nRow = 1;
	bool nEnd = false;
	nBug = new UINT[32];
	memset(nBug, 0, sizeof(UINT) * 32);
	nBug[0] = 0;
	StroenieLabir();
	do {
		SetCursor(nRow, nCol * 2);
		cout << "ж" << (char)184;
		SetColor();

		sKey = _getch();
		SetCursor(nRow, nCol * 2);
		cout << "  ";
		switch (sKey)
		{
		case 72: //вверх
			if ((nRow > 1) && !(nLab[nRow - 1] & (nBit >> nCol)))
				nRow--;
			else
				Beep(550, 350); break;
		case 80: //вниз
			if ((nRow < 31) && !((nLab[nRow + 1] & (nBit >> nCol))))
				nRow++;
			else
				Beep(550, 350); break;
		case 75: //влево
			if ((nCol > 1) && !((nLab[nRow] & (nBit >> (nCol - 1)))))
				nCol--;
			else
				Beep(550, 350); break;
		case 77: //вправо
			if ((nCol < 31) && !((nLab[nRow] & (nBit >> (nCol + 1)))))
				nCol++;
			else
				Beep(550, 350); break;
		case 63: Moving(nRow, nCol); break; // автопоиск (F5)
		default:
			break;
		}
		if (nRow == nEndRow && nCol == nEndCol) {
			SetColor(CL_LIGHT_GREEN, 0);
			system("cls");
			cout << "\n\tЛабиринт пройден!" << endl;
			SetColor();
			break;
		}
	} while (sKey != 27);
}
void LabirWay() {
	SetConsoleTitle(TEXT("Путь из лабиринита"));
	int nCol = 2, nRow = 1;
	bool nEnd = false;
	nBug = new UINT[32];
	memset(nBug, 0, sizeof(UINT) * 32);
	nBug[0] = 0;
	StroenieLabir();
	Moving(nRow, nCol);// автопоиск (F5)
	SetColor(CL_GREEN, 0);
	SetCursor(36, 0);
	cout << "\n\tПуть найден!";
	SetColor();
}
void StroenieLabir() {
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (nEndRow == i && nEndCol == j)
				SetColor(0, 4);
			if (nBegRow == i && nBegCol == j)
				SetColor(0, 10);
			if (((nBit >> j) & nLab[i])) {
				SetColor(2, 7);
				cout << (char)135 << (char)135;
			}
			else
				cout << "  ";
			SetColor();

		}
		cout << "\n";
	}
}