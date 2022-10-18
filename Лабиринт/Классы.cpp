#include "header.h"
#include "MyFunction.h"
#include "Classes.h"



void MyClasses() {

	cout << endl;
	SetColor(CL_LIGHT_GREEN, 0);
	cout << "\t Меню Классов\n" << endl;
	SetColor();
	cout << "1 - создать треугольник" << endl;
	cout << "2 - создать прямоугольник" << endl;
	cout << "3 - создать эллипс" << endl;
	cout << "4 - передвинуть фигуру по номеру" << endl;
	cout << "5 - нарисовать линию между фигурами" << endl;
	cout << "6 - отобразить только один вид фигур" << endl;
	cout << "Esc - выход из меню классов" << endl;


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
			cout << "введите номер фигуры, координату х, координату у" << endl;
			cin >> nId >> nKorX >> nKorY;
			Manager.Moving(nId, nKorX, nKorY);
		}	break;
		case'5': {cout << "введите номера фигур" << endl;
			cin >> nId >> nKorX;
			if (nId < Manager.getfigurecount() && nKorX < Manager.getfigurecount())
				Manager.ADDline(nId, nKorX);
			else cout << "введеных фигур не существует" << endl;
		}	break;
		case'6': {
			cout << "введите имя фигуры" << endl;
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