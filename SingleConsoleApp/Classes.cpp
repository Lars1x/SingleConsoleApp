#include "header.h"
#include "MyFunction.h"
#include "Classes.h"



void MyClasses() {

	cout << endl;
	SetColor(CL_LIGHT_GREEN, 0);
	cout << "\t ���� �������\n" << endl;
	SetColor();
	cout << "1 - ������� �����������" << endl;
	cout << "2 - ������� �������������" << endl;
	cout << "3 - ������� ������" << endl;
	cout << "4 - ����������� ������ �� ������" << endl;
	cout << "5 - ���������� ����� ����� ��������" << endl;
	cout << "6 - ���������� ������ ���� ��� �����" << endl;
	cout << "Esc - ����� �� ���� �������" << endl;


	FigurManager Manager;
	char sKey;
	int nId = 0, nKorX = 0, nKorY = 0;
	string nFileName;
	do {
		sKey = _getch();
		switch (sKey) {
		case'1': Manager.ADDtriangle(250, 400, 350, 500);	 break;
		case'2': Manager.ADDrectangle(400, 400, 500, 500);	 break;
		case'3': Manager.ADDellipse(600, 400, 700, 500);	 break;
		case'4': {
			cout << "������� ����� ������, ���������� �, ���������� �" << endl;
			cin >> nId >> nKorX >> nKorY;
			Manager.Moving(nId, nKorX, nKorY);
		}	break;
		case'5': {cout << "������� ������ �����" << endl;
			cin >> nId >> nKorX;
			if (nId < Manager.getfigurecount() && nKorX < Manager.getfigurecount())
				Manager.ADDline(nId, nKorX);
			else cout << "�������� ����� �� ����������" << endl;
		}	break;
		case'6': {
			cout << "������� ��� ������" << endl;
			cin >> nId; Manager.selectfigure(nId);
			system("cls");
		}	break;
		case 75:Manager.MoveAll(sKey);	break;
		case 72:Manager.MoveAll(sKey);	break;
		case 77:Manager.MoveAll(sKey);	break;
		case 80:Manager.MoveAll(sKey);	break;
		case 27:							break;
		}
	
		Manager.DrawFig();
	} while (sKey != 27);
	system("cls");
}