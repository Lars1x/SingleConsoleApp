#pragma once
#include "Header.h"

typedef struct _stRecursion {
	int nIdRec;		// Идентификатор записи
double nItem,		// Значение члена ряда
nSumItem;			// Накопленная сумма членов ряда
_stRecursion() {
	nIdRec = 0;
	nItem = 0;
	nSumItem = 0;
}
} stRecursion, * pstRecursion;

void Recursion();
double Rec(int i, double step, double eps, double Z, double NewZ, double OldZ);
int DrawGraf(pstRecursion pRec, int pnCount = 0, int HeiGraph = 300, int WidGraph = 600);