#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int t, a, b, c, l;
	cout << "Введите нужное условие (от 1 до 4): ";
	cin >> t;

	switch (t)
	{
	case 1: cout << "8*9*10*11*12*13*14*15 = " << 8 * 9 * 10 * 11 * 12 * 13 * 14 * 15; break;

	case 2: b = 1; cout << "Введите значение a = "; cin >> a; l = a; for (a; a <= 20; ++a) { b *= a; } cout << "Произведение чисел от " << l << " до 20 = " << b; break;

	case 3: c = 1; cout << "Введите значение b = "; cin >> b; l = b; for (int i = 1; i <= b; ++i) { c *= i; }	cout << "Произведение чисел от 1 до " << l << " = " << c; break;

	case 4: c = 1; cout << "Введите значение a,b (b>=a) : "; cin >> a >> b; l = a; for (a; a <= b; ++a) { c *= a; } cout << "Произведение чисел от " << l << " до " << b << " = " << c; break;
	}
}