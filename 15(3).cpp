#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int N,a;

	cout << "Введите нужное условие (1 или 2): ";
	cin >> a;

	switch (a)
	{

	case 1: 
		for (int i = 1; i < 10; ++i) 
			cout << i << " * " << 7 << " = " << i * 7 << endl; 
		break;

	case 2:
	{
		cout << "Введите N: ";
		cin >> N;

		for (int i = 1; i <= 9; ++i)
			cout << i << " x " << N << " = " << i * N << endl;
	}

	}
}