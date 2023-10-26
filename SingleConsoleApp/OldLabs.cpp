#include "Header.h"



void lab1()
{
	SetConsoleTitle(TEXT("Лабораторная работа №1"));
	double A, B, C, D, E, F, Z;
	cout << "Введите значение А = ";
	cin >> A;
	cout << "Введите значение B = ";
	cin >> B;
	cout << "Введите значение C = ";
	cin >> C;
	cout << "Введите значение D = ";
	cin >> D;
	E = fmin(fmin(A, B), fmin(C, D));
	if (E <= 0)
	{
		F = -1;
	}
	else
	{
		F = 1;
	}
	Z = E - F * 0.75;
	cout << "\n Е = " << E << "	F = " << F << "	Z = " << Z << endl;
}
void lab2()
{
	SetConsoleTitle(TEXT("Лабораторная работа №2"));
	double A, B, C;
	cout << "Введите значение А = ";
	cin >> A;
	cout << "Введите значение B = ";
	cin >> B;
	cout << "Введите значение C = ";
	cin >> C;
	cout << endl;
	if (A <= 0 || B <= 0 || C <= 0 || A + B <= C || A + C <= B || B + C <= A)
	{
		cout << "Ошибка. Невозможно составить треугольник" << endl;
	}
	else
	{
		if (C * C == A * A + B * B)
		{
			cout << "С является гипотенузой прямоугольного  треугольника, А, B - катеты" << endl;

		}
		else if (B * B == A * A + C * C)
		{
			cout << "B является гипотенузой прямоугольного  треугольника, B, C - катеты" << endl;

		}
		else if (A * A == B * B + C * C)
		{
			cout << "A является гипотенузой прямоугольного  треугольника, C, B - катеты" << endl;

		}
		else
		{
			cout << "Треугольник не является прямоугольным" << endl;
		}
	}
}
void lab3()
{
	SetConsoleTitle(TEXT("Лабораторная работа №3"));
	const int N = 10;						// количество значеий массива
	double nMassX[N], nMassA[N], C, y = 0;
	int i;
	cout << "Введите " << N << " значений переменной X: " << endl;
	for (i = 0; i < N; i++)
	{
		cout << "X[" << i + 1 << "] = ";
		cin >> nMassX[i];
	}
	cout << "Введите значение С = ";
	cin >> C;
	for (i = 0; i < N; i++)
		y += (nMassX[i] - C) / (nMassX[i] * nMassX[i]);
	cout << "y = " << y << endl;
	for (i = 0; i < N; i++)
	{
		nMassA[i] = y - nMassX[i];
		cout << "A[" << i + 1 << "] = " << nMassA[i] << endl;
	}
	double Mxn, max = nMassA[0], min = nMassA[0];
	for (i = 1; i < N; ++i)
	{
		if (max < nMassA[i])
			max = nMassA[i];
		if (min > nMassA[i])
			min = nMassA[i];
	}
	Mxn = fabs(max - min);
	if (Mxn == 0)
		cout << "Абсолютная разница = 0, дальнейшие вычисления невозможны." << endl;
	else
	{
		cout << "Абсолютная разница = " << Mxn << endl;
		for (i = 0; i < N; ++i)
		{
			nMassA[i] = nMassA[i] / Mxn;
			cout << "A[" << i + 1 << "] = " << nMassA[i] << endl;
		}
	}
}
void lab4()
{
	SetConsoleTitle(TEXT("Лабораторная работа №4"));
	const int ROW = 5;                //размерность квадатной матрицы
	double nMatrix[ROW][ROW], sum;
	int i, j;
	bool c = false;
	for (i = 0; i < ROW; ++i)
	{
		cout << "Введите " << (i + 1) << " строку матрицы : " << ROW << " элементов через пробел" << endl;
		for (j = 0; j < ROW; j++)
			cin >> nMatrix[i][j];
	}
	cout << "Ввведенная матрица:" << endl;
	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < ROW; j++)
			cout << setw(4) << nMatrix[i][j];
		cout << endl;
	}
	sum = 0;
	for (i = 0; i < ROW; ++i)
		if (nMatrix[i][i] < 0)
		{
			c = true;
			for (j = 0; j < ROW; j++)
				sum += nMatrix[i][j];
		}
	if (c == false)
		cout << "Ошибка, на главной диагонали данной матрицы нет отрицательных элементов.";
	else
	{
		cout << "Сумма эллементов равна: " << sum << endl;
		cout << "Новая матрица:" << endl;
		for (i = 0; i < ROW; ++i)
		{
			nMatrix[i][ROW - 1] *= sum;
			for (j = 0; j < ROW; j++)
				cout << setw(4) << nMatrix[i][j];
			cout << endl;
		}
	}
}