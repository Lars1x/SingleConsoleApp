#include "Header.h"

void mask()
{
	SetConsoleTitle(TEXT("�������� � ������"));
	short A[20], mask;
	cout << "������� �����:  ";
	cin >> mask;
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		A[i] = rand();
		if (A[i] & mask)
			cout << A[i] << "  ";
	}
	cout << endl;
}