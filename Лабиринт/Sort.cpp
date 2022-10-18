#include "Header.h"
#include "MyFunction.h"


void Sort(string psp[10], char dir){
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (psp[i].compare(psp[j]) * dir > 0) {
				string sbuf = psp[i];
				psp[i] = psp[j];
				psp[j] = sbuf;
			}
		}
	}
}

void BoubleSort(string psp[10], char dir) {
	int n;
	do {
		n = 0;
		for (int i = 0; i < 9; i++) {
			if (psp[i].compare(psp[i + 1]) * dir > 0) {
				string sbuf = psp[i];
				psp[i] = psp[i + 1];
				psp[i + 1] = sbuf;
				n++;
			}
		}
	} while (n != 0);
}


void QuickSort(string psp[10], int first, int last, char dir)
{
	int left = first, right = last;
	string buf;
	string mid = psp[(left + right) >> 1];
	while (left <= right) {
		while (psp[left].compare(mid) * dir < 0)
			left++;
		while (psp[right].compare(mid) * dir > 0)
			right--;
		if (left <= right) {
			swap(psp[left], psp[right]);
			left++;
			right--;
		}
	}
	if (first < right)
		QuickSort(psp, first, right, dir);
	if (left < last)
		QuickSort(psp, left, last, dir);

}
void OutputPSP(string psp[10])
{
	for (int i = 0; i < 10; i++)
		cout << " " << psp[i] << endl;
}