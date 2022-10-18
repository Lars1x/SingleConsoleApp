#include "Header.h"



void lab1()
{
	SetConsoleTitle(TEXT("������������ ������ �1"));
	double A, B, C, D, E, F, Z;
	cout << "������� �������� � = ";
	cin >> A;
	cout << "������� �������� B = ";
	cin >> B;
	cout << "������� �������� C = ";
	cin >> C;
	cout << "������� �������� D = ";
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
	cout << "\n � = " << E << "	F = " << F << "	Z = " << Z << endl;
}
void lab2()
{
	SetConsoleTitle(TEXT("������������ ������ �2"));
	double A, B, C;
	cout << "������� �������� � = ";
	cin >> A;
	cout << "������� �������� B = ";
	cin >> B;
	cout << "������� �������� C = ";
	cin >> C;
	cout << endl;
	if (A <= 0 || B <= 0 || C <= 0 || A + B <= C || A + C <= B || B + C <= A)
	{
		cout << "������. ���������� ��������� �����������" << endl;
	}
	else
	{
		if (C * C == A * A + B * B)
		{
			cout << "� �������� ����������� ��������������  ������������, �, B - ������" << endl;

		}
		else if (B * B == A * A + C * C)
		{
			cout << "B �������� ����������� ��������������  ������������, B, C - ������" << endl;

		}
		else if (A * A == B * B + C * C)
		{
			cout << "A �������� ����������� ��������������  ������������, C, B - ������" << endl;

		}
		else
		{
			cout << "����������� �� �������� �������������" << endl;
		}
	}
}
void lab3()
{
	SetConsoleTitle(TEXT("������������ ������ �3"));
	const int N = 10;						// ���������� ������� �������
	double nMassX[N], nMassA[N], C, y = 0;
	int i;
	cout << "������� " << N << " �������� ���������� X: " << endl;
	for (i = 0; i < N; i++)
	{
		cout << "X[" << i + 1 << "] = ";
		cin >> nMassX[i];
	}
	cout << "������� �������� � = ";
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
		cout << "���������� ������� = 0, ���������� ���������� ����������." << endl;
	else
	{
		cout << "���������� ������� = " << Mxn << endl;
		for (i = 0; i < N; ++i)
		{
			nMassA[i] = nMassA[i] / Mxn;
			cout << "A[" << i + 1 << "] = " << nMassA[i] << endl;
		}
	}
}
void lab4()
{
	SetConsoleTitle(TEXT("������������ ������ �4"));
	const int ROW = 5;                //����������� ��������� �������
	double nMatrix[ROW][ROW], sum;
	int i, j;
	bool c = false;
	for (i = 0; i < ROW; ++i)
	{
		cout << "������� " << (i + 1) << " ������ ������� : " << ROW << " ��������� ����� ������" << endl;
		for (j = 0; j < ROW; j++)
			cin >> nMatrix[i][j];
	}
	cout << "���������� �������:" << endl;
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
		cout << "������, �� ������� ��������� ������ ������� ��� ������������� ���������.";
	else
	{
		cout << "����� ���������� �����: " << sum << endl;
		cout << "����� �������:" << endl;
		for (i = 0; i < ROW; ++i)
		{
			nMatrix[i][ROW - 1] *= sum;
			for (j = 0; j < ROW; j++)
				cout << setw(4) << nMatrix[i][j];
			cout << endl;
		}
	}
}