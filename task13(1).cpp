#include <iostream>
using namespace std;

int main()
{
	int x, y, z, t;
	setlocale(LC_ALL, "Rus");

	cout << "Введите числа x, y, z: ";
	cin >> x >> y >> z;
	cout << endl;

    pigpeppa:

	cout << "Введите номер нужного условия (если хотите закончить выполнение программы введите 0) : ";
	cin >> t;

	if (t == 0 || t >= 7) { return 0; }

	switch(t)
	{
	case 1: if (abs(x) % 2 == 1 && abs(y) % 2 == 1) { cout << "Первое условие истинно"; break; }
		  else { cout << "Первое условие ложно"; break; }

	case 2: if (x < 20 && y >= 20 || x >= 20 && y < 20) { cout << "Второе условие истинно"; break; }
		  else { cout << "Второе условие ложно"; break; }

	case 3: if (x == 0 || y == 0) { cout << "Третье условие истинно"; break; }
		  else { cout << "Третье условие ложно"; break; }

	case 4: if (x<0 && y<0 && z<<0) { cout << "Четвертое условие истинно"; break; }
		  else { cout << "Четвертое условие ложно"; break; }

	case 5: if (abs(x) % 5 == 0 && abs(y) % 5 != 0 && abs(z) % 5 != 0 || abs(x) % 5 != 0 && abs(y) % 5 == 0 && abs(z) % 5 != 0 || abs(x) % 5 != 0 && abs(y) % 5 != 0 && abs(z) % 5 == 0) { cout << "Пятое условие истинно"; break; }
		  else { cout << "Пятое условие ложно"; break; }

	case 6: if (x>100 || y>100 || z>100) { cout << "Шестое условие истинно"; break; }
		  else { cout << "Шестое условие ложно"; break; }
	}

	cout << endl << endl;

	goto pigpeppa;
}
