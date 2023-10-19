#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

double *arr;

void task1()
{
	int N,a;
	cout << "Введите количество элементов в массиве: ";
	cin >> N;
	arr = new double[N];
	cout << "Введите элементы массива: ";
	for (int i = 0; i < N; ++i) cin >> arr[i];

	cout << endl;

	cout << "Увеличиваем элементы массива в 2 раза: ";
	for (int i = 0; i < N; ++i) cout << arr[i] * 2 << " ";

	cout << endl << endl;

	cout << "Уменьшаем элементы массива на число a: " << endl;
	cout << "Введите число a: ";
	cin >> a;
	for (int i = 0; i < N; ++i) cout << arr[i] - a << " ";

	cout << endl << endl;

	cout << "Делим элементы массива на первый элемент массива: ";
	for (int i = 0; i < N; ++i) cout << arr[i] / arr[0] << " ";

	cout << endl;
}

void task2()
{
	int N, k1, k2, s1, s2;
	double sum1, sum2, sum3, sum4, sum5;
	sum1 = 0; sum2 = 0; sum3 = 0; sum4 = 0; sum5 = 0;
	cout << "Введите количество элементов в массиве: ";
	cin >> N;
	arr = new double[N];
	cout << "Введите элементы массива: ";
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		sum1 += arr[i];
		sum2 += pow(arr[i], 2);
		if (i < 6) sum3 += arr[i];
	}
	
	cout << "Сумма элементов массива = " << sum1 << endl;
	cout << "Сумма квадратов элементов массива = " << sum2 << endl;
	cout << "Сумма первых 6 элементов массива = " << sum3 << endl << endl;
	cout << "Введите значения k1 и k2 с которого и по который будут суммироваться элементы массива" << endl;
	cout << "k1 и k2 = ";
	cin >> k1 >> k2;
	for (int i = k1; i <= k2; ++i) sum4 += arr[i];
	cout << "Сумма элементов с k1 по k2 = " << sum4 << endl;
	cout << "Среднее арифметическое всех элементов массива = " << sum1 / N << endl;
	cout << "Введите значения s1 и s2 с которого и по которое будет считаться среднее арифметическое элементов" << endl;
	cout << "s1 и s2 = ";
	cin >> s1 >> s2;
	for (int i = s1; i <= s2; ++i) sum5 += arr[i];
	cout << "Среднее арифметическое элементов с s1 по s2 " << sum5 / (s2 - s1 + 1) << endl;
}

void task3()
{
	double a;
	arr = new double[20];
	cout << "Введите элементы массива 20 элементов: ";
	for (int i = 0; i < 20; ++i) cin >> arr[i];
	cout << "Переставить первые 3 и последние 3 элемента местами сохранив порядок" << endl;
	for (int i = 0; i < 3; ++i)
	{
		a = arr[17 + i];
		arr[17 + i] = arr[i];
		arr[i] = a;
	}
	for (int i = 0; i < 20; ++i) cout << arr[i] << " ";
	cout << endl;
}

void task4()
{
	int N, a, b, c, k, l;
	a = -1; b = -1;
	k = 0; l = 0;
	vector <int> v;
	cout << "Введите количество элементов массива: ";
	cin >> N;
	cout << "Введите элементы массива" << endl;
	for (int i = 0; i < N; ++i)
	{
		cin >> c;
		v.push_back(c);
	}

	for (int i = 0; i < N; ++i)
	{
		if (v[i] < 0 && k == 0)
		{
			a = i;
			k += 1;
		}

		if (v[N-i-1] % 2 == 0 && l == 0)
		{
			b = N-i-1;
			l += 1;
		}
	} 

	if (a > -1) v.erase(v.begin() + a);
	if (b > -1 && b > a && a > -1) v.erase(v.begin() + b - 1);
	if (b > -1 && b < a && a > -1) v.erase(v.begin() + b);
	if (b > -1 && a == -1) v.erase(v.begin() + b);

	if (k == 1) { N -= 1; };
	if (l == 1) { N -= 1; };

	for (int i = 0; i < N; ++i) cout << v[i] << " ";
}

void task5()
{
	string a;
	cout << "Введите название города: ";
	cin >> a;
	cout << "Количество букв в городе = " << a.length();
}

void task6()
{
	string a, b;
	cout << "Введите первую и вторую фамилию через пробел: ";
	cin >> a >> b;
	if (a.length() > b.length())
	{
		cout << "true";
	}

	else { cout << "false"; }
}

void task7()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string a, b, c, the_longest, the_shortest;
	int a1, b1, c1;
	cout << "Введите название 3 городов через пробел: ";
	cin >> a >> b >> c;
	a1 = a.length();
	b1 = b.length();
	c1 = c.length();

	if (a1 > b1 && a1 > c1) { the_longest = a; }
	if (b1 > a1 && b1 > c1) { the_longest = b; }
	if (c1 > a1 && c1 > b1) { the_longest = c; }

	if (a1 < b1 && a1 < c1) { the_shortest = a; }
	if (b1 < a1 && b1 < c1) { the_shortest = b; }
	if (c1 < a1 && c1 < b1) { the_shortest = c; }

	cout << "Самое длинное слово - " << the_longest << endl;
	cout << "Самое короткое слово - " << the_shortest;
	
}

void task8()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string a, b;
	int k;
	cout << "Введите слово: ";
	cin >> a;
	k = a.length();

	for (int i = 1; i <= k; ++i)
	{
		b += "*";
	}

	cout << b + a + b;
}

void task9()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string a;
	double b,k,t;
	k = 0; t = 0;
	cout << "Введите предложение: ";
	cin.ignore();
	getline(cin,a);
	b = a.length();
	for (int i = 0; i < b; ++i)
	{
		if (a[i] == 'а') { k += 1; }
		if (a[i] == ' ') { t += 1; }
	}

	cout << "Процентное содержание буквы 'а' в предложении = " << (k / (b-t))*100 << "%";
}

void task10()
{
	int m, z;
	string a = "Can you can a can as a canner can can a can ?";
	string b = "Can ";
	string c = "can ";
	string d = "new_word";
	m = a.find(b);

	while (m != -1)
	{
		a.erase(m, 3);
		a.insert(m, d);
		m = a.find(b);
	}

	z = a.find(c);

	while (z != -1)
	{
		a.erase(z, 3);
		a.insert(z, d);
		z = a.find(c);
	}

	cout << "Строка с замененными словами: " << a;

}

int main()
{
	setlocale(LC_ALL, "Rus");	
	int a;
	cout << "Введите номер задачи: ";
	cin >> a;

	switch (a)
	{
	case 1: task1(); break;

	case 2: task2(); break;

	case 3: task3(); break;

	case 4: task4(); break;

	case 5: task5(); break;

	case 6: task6(); break;

	case 7: task7(); break;

	case 8: task8(); break;

	case 9: task9(); break;

	case 10: task10(); break;
	}
}