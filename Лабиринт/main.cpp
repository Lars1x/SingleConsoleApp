// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "header.h"
#include "MyFunction.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned char sKey;
	bool bout = false;
	do
	{
		SetConsoleTitle(TEXT("Учебное приложение"));
		setlocale(LC_ALL, "Russian");
		system("cls");
		cout << "\tМеню приложения" << endl << endl;
		cout << "1 - Лабораторная работа 1" << endl;
		cout << "2 - Лабораторная работа 2" << endl;
		cout << "3 - Лабораторная работа 3" << endl;
		cout << "4 - Лабораторная работа 4" << endl;
		cout << "5 - Операция с маской" << endl;
		cout << "6 - Лабиринт" << endl;
		cout << "7 - Рекурсивная функция" << endl;
		cout << "8 - Cортировока списка" << endl;
		cout << "9 - Шифрование текста" << endl;
		cout << "K - Классы" << endl << endl;
		cout << "0 - О программе..." << endl;
		cout << "Esc - Выход из программы" << endl;

		sKey = _getch();
		system("cls");
		switch (sKey)
		{
		case '0': Creator();    break;
		case '1': lab1();       break;
		case '2': lab2();       break;
		case '3': lab3();       break;
		case '4': lab4();       break;
		case '5': mask();       break;
		case '6': {
			cout << "\t Меню Лабиринта" << endl;
			cout << "1 - Лабиринт" << endl;
			cout << "2 - Показать выход из Лабиринта" << endl;
			cout << "Esc - Вернуться назад" << endl;

			sKey = _getch();
			system("cls");
			switch (sKey)
			{
			case '1': Labir();      break;
			case '2': LabirWay();   break;
			case 27: main();      break;
			default:
				break;
			}
		};		break;
		case '7': Recursion();  break;
		case'8':{
			string spisok[10]{ "Кузьмин", "Иванов", "Леонов", "Макаров", "Бардин", "Абрамов", "Фурсов",
				"Келлер", "Любимов", "Мельников" };
			SetColor(11, 0);
			cout << "\tИзначальный список:" << endl << endl;
			SetColor();
			for (int i = 0; i < 10; i++) cout << " " << spisok[i] << endl;
			cout << endl;
			SetColor(14, 0);
			cout << "\tПредложенные выды Cортировки:\n\n";
			SetColor();
			cout << " 1 - Сортировка методом поиска позиции в ряду  (A -> Я)" << endl;
			cout << " 2 - Сортировка методом поиска позиции в ряду  (Я -> А)" << endl;
			cout << " 3 - Cортировка 'Пузыриком'  (А -> Я)" << endl;
			cout << " 4 - Cортировка 'Пузыриком'  (Я -> А)" << endl;
			cout << " 5 - Быстрая сортировка  (А -> Я)" << endl;
			cout << " 6 - Быстрая сортировка  (Я -> А)\n" << endl;
			cout << " Вернуться в главное меню: Q" << endl << endl;
			
			sKey = _getch();
			switch (sKey)
			{
			case '1':
				Sort(spisok, 1);
				SetColor(11, 0);
				cout << "\tОтсортированный список методом поиска позиции в ряду  (A -> Я)" << endl << endl;
				SetColor();
				OutputPSP(spisok);		break;
			case '2':
				Sort(spisok, -1);
				SetColor(11, 0);
				cout << "\tОтсортированный список методом поиска позиции в ряду  (Я -> А)" << endl << endl;
				SetColor();
				OutputPSP(spisok);		break;
			case '3':
				BoubleSort(spisok, 1);
				SetColor(11, 0);
				cout << "\tОтсортированный список 'Пузыриком'  (Я -> А)" << endl << endl;
				SetColor();
				OutputPSP(spisok);		break;
			case '4':
				BoubleSort(spisok, -1);
				SetColor(11, 0);
				cout << "\tОтсортированный список 'Пузыриком'  (Я -> А)" << endl << endl;
				SetColor();
				OutputPSP(spisok);		break;
			case '5':
				QuickSort(spisok, 0, 9, 1);
				SetColor(11, 0);
				cout << "\tОтсортированный список методом быстрой сортировки  (А -> Я)" << endl << endl;
				SetColor();
				OutputPSP(spisok);		break;
			case '6':
				QuickSort(spisok, 0, 9, -1);
				SetColor(11, 0);
				cout << "\tОтсортированный список методом быстрой сортировки  (Я -> А)" << endl << endl;
				SetColor();
				OutputPSP(spisok);		break;
			case 27: main();			break;
			default:
				break;
			}
		} break;
		case '9':{
			cout << "\tКодировка и раскодировка текста\n\n";
			cout << "Текст: "; Shifr();
			cout << endl;
			cout << "1 - Закодировать текст" << endl;
			cout << "2 - Раскодировать текст" << endl;
			cout << "Esc - вернуться в основное меню" << endl;

			cout << endl;
			do {
				sKey = _getch();
				switch (sKey)
				{
				case '1':encode();		break;
				case '2':decode();		break;
				case 27: main();		break;
				default:
					break;
				}
				cout << endl;
			} while (sKey != 27); 
		}	break;
		case 'K':;
		case 'k': MyClasses(); break;
		default:                break;
		}
		if (sKey != 27)
		{
			cout << " \n\n ";
			system("pause");
			bout = true;
		}
	} while (bout);
	return 0;
}



void Creator()
{
	SetConsoleTitle(TEXT("Создатель приложения"));
	cout << "Создатель программы:  студент группы 1бИТС2 - Бардин Н.А." << endl;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
