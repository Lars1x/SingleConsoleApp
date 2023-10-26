#include "Recursion.h"
#include "Header.h"
#include "MyFunction.h"


pstRecursion stRec;
int nCount = 0;


void DrawLine(HDC hdc, int x1, int y1, int x2, int y2, int Color, int pWidLine, int typepen) {
	HPEN holdpen, hPen = CreatePen(typepen, pWidLine, Color);
	holdpen = (HPEN)SelectObject(hdc, hPen);
	SelectObject(hdc, hPen);
	MoveToEx(hdc, x1, y1, NULL);    // координаты начальной точки
	LineTo(hdc, x2, y2);			// координаты конечной точки
	DeleteObject(hPen);
}

double Max(pstRecursion pRec, int nRec) {
	if ((pRec == NULL) || (nRec == 0)) return 0;
	double nMax = pRec[0].nItem;
	for (int i = 0; i < nRec; i++) {
		if (nMax < pRec[i].nItem) nMax = pRec[i].nItem;
		if (nMax < pRec[i].nSumItem) nMax = pRec[i].nSumItem;
	}
	return nMax;
}

double Min(pstRecursion pRec, int nRec) {
	if ((pRec == NULL) || (nRec == 0)) return 0;
	double nMin = pRec[0].nItem;
	for (int i = 0; i < nRec; i++) {
		if (nMin > pRec[i].nItem) nMin = pRec[i].nItem;
		if (nMin > pRec[i].nSumItem) nMin = pRec[i].nSumItem;
	}
	return nMin;
}



int DrawGraf(pstRecursion pRec, int pnCount, int pnHeiGraph, int pnWidGraph) {
	if ((pRec == NULL) || (pnCount == 0)) return 0;		//не данных, не рисуем график
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	int nStartGraphY = 15 + pnCount;
	nStartGraphY *= 20;

	int nSec = 5;
	int nEndGraphY = nStartGraphY + pnHeiGraph;
	int indent = 150;
	double nMax = Max(pRec, pnCount), nMin = Min(pRec, pnCount);
	double PxPerValY = pnHeiGraph / (Max(pRec, pnCount) - Min(pRec, pnCount));	//коэфициент по оси y
	double PxPerValX = pnWidGraph / (pnCount - 1);

	SetBkColor(hdc, 0);
	SetColor(14, 0);
	SetTextColor(hdc, RGB(255, 255, 255));

	DrawLine(hdc, indent, nStartGraphY, indent, nEndGraphY, RGB(255, 255, 255), 2, PS_SOLID);				//отрисовка вертигальной линии 
	DrawLine(hdc, indent, nEndGraphY, indent + pnWidGraph, nEndGraphY, RGB(255, 255, 255), 2, PS_SOLID);	//отрисовка горизонтальной линии 

	char* nums = new char[20];
	memset(nums, 0, 20);

	HFONT hfontold,
		hfont = CreateFontA(24, 10, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	SetTextColor(hdc, RGB(30, 205, 245));
	hfontold = (HFONT)SelectObject(hdc, hfont);
	TextOutA(hdc, indent + (pnWidGraph) / 3, nEndGraphY + 45, "Индефикатор данных", ARRAYSIZE("Индефикатор данных"));
	TextOutA(hdc, indent + (pnWidGraph) / 4, nStartGraphY - 45, "График рекурентного уравнения", ARRAYSIZE("График рекурентного уравнения"));
	SetTextColor(hdc, RGB(255, 255, 0));

	int x1, x2, y1, y2;
	for (int i = 0; i < pnCount; i++)								//отрисовка вертикальных пунктирных линий 
	{
		x1 = indent + PxPerValX * i;
		x2 = x1;
		y1 = nStartGraphY;
		y2 = nEndGraphY;
		DrawLine(hdc, x1, y1, x2, y2, RGB(75, 75, 75), 1, PS_DOT);
		snprintf(nums, sizeof(nums) * 20, "%d", i + 1);
		TextOutA(hdc, x1 - 5, nEndGraphY + 10, nums, 2);
	}


	hfont = CreateFontA(24, 10, 900, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	SetTextColor(hdc, RGB(30, 205, 245));
	(HFONT)SelectObject(hdc, hfont);
	TextOutA(hdc, 10, nEndGraphY - (pnHeiGraph / 3), "Значение", 8);

	SetTextColor(hdc, RGB(255, 255, 255));
	hfont = CreateFontA(24, 10, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	(HFONT)SelectObject(hdc, hfont);
	DeleteObject(hfont);

	double nStep = nMax + abs(nMin);
	double nOnePxY = nStep / pnHeiGraph;   // значение в 1 пикселе
	nStep /= 9;
	double buff = nMin;



	for (int i = 0; i < 10; i++)
	{
		x1 = indent;
		x2 = indent + pnWidGraph;
		double nVal = i * PxPerValY * (nMax) / nSec;
		y1 = nEndGraphY - nVal;
		y2 = y1;
		if (i != 0)DrawLine(hdc, x1, y1, x2, y2, RGB(75, 75, 75), 1, PS_DOT);  // отрисовка горизонтальных штриховых линий
		if (i == 0) snprintf(nums, sizeof(nums) * 20, "%10.5f", nMin);
		else snprintf(nums, sizeof(nums) * 20, "%10.5f", buff += nStep);
		TextOutA(hdc, x1 - 70, y1-16, nums, 7);
	}
	for (int i = 0; i < pnCount - 1; i++) {						//Отрисовка графика значения члена ряда
		x1 = indent + PxPerValX * i;
		x2 = indent + PxPerValX * (i + 1);
		y1 = nStartGraphY + (pnHeiGraph - (pRec[i].nItem * PxPerValY)) + nMin* PxPerValY;
		y2 = nStartGraphY + (pnHeiGraph - (pRec[i+1].nItem * PxPerValY)) + nMin * PxPerValY;
		DrawLine(hdc, x1, y1, x2, y2, RGB(255, 0, 0), 2, PS_DOT);
	}
	for (int i = 0; i < pnCount - 1; i++) {						//Отрисовка графика накопленной суммы
		x1 = indent + PxPerValX * i;
		x2 = indent + PxPerValX * (i + 1);
		y1 = nStartGraphY + (pnHeiGraph - (pRec[i].nSumItem * PxPerValY)) + nMin * PxPerValY;
		y2 = nStartGraphY + (pnHeiGraph - (pRec[i + 1].nSumItem * PxPerValY)) + nMin * PxPerValY;
		DrawLine(hdc, x1, y1, x2, y2, RGB(0, 255, 0), 2, PS_DOT);
	}
	SetColor(15, 0);
	_getch();
	return nEndGraphY + 16 * 3;
}


double Rec(int i, double step, double eps, double Z, double NewZ, double OldZ) {
	if ((fabs(NewZ-OldZ)) > eps)
	{
		OldZ = NewZ;									// присваивание следующего знаачения последовательности предыдущему члену //1.25
		NewZ = OldZ * step;								// шак последовательности 
		Z += NewZ;										// присваивание накопленного значения 
		stRec[i - 1].nIdRec = i;
		stRec[i - 1].nItem = NewZ;
		stRec[i - 1].nSumItem = Z;
		i++;
		nCount++;
		return Rec(i, step, eps, Z, NewZ, OldZ);
	}
	return nCount, Z;

}

void Recursion()
{
	double a, y, e, Z = 0;
	double OldZ, NewZ;
	int i = 1;
	stRec = new stRecursion[100];
	memset(stRec, 0, sizeof(stRecursion) * 100);
	cout << "Введите константу 'y' = "; cin >> y;
	cout << "Введите константу 'a' = "; cin >> a;
	cout << "Точность вычислений = "; cin >> e;
	cout << endl;
	double step = -y / a;
	NewZ = (-1) * step;				// Первый член последовательности 
	Z = NewZ;						// Присваивание первого члена последовательности сумме
	OldZ = 0;
	NewZ = (-1) * step;
	if ((abs(y) <= 1) && (a > y))
	{
		SetColor(CL_LIGHT_YELLOW, 0);
		cout << "\tРешение рекуррентного уравнения\n" << setw(5) << "\t  Методом рекурентного вызова\n\n";
		SetColor(10, 0);
		cout << setw(4) << "id" << setw(15) << "Член ряда" << setw(25) << "Накопленная значение" << endl << endl;
		SetColor();
		Z = Rec(i, step, e, Z, NewZ, OldZ);
		for (int i = 0; i < nCount; i++)
			cout << setw(4) << stRec[i].nIdRec << setw(15) << stRec[i].nItem << setw(20) << stRec[i].nSumItem << endl;
		SetColor(12, 0);
		cout << "\n\  Накопленное значение ряда Z = " << Z <<endl;
		int nHei = DrawGraf(stRec, nCount);
		
	}
	else
	{
		SetColor(CL_RED, 0);
		cout << "\tВведенные значения констант не удовлетворяют условия";
		SetColor();
	}
}
