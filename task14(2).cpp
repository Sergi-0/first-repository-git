#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int t;
	using byte = int;
	pair<byte, byte> positionA;
	pair<byte, byte> positionB;
	cout << "Введите координаты A(столбец,ряд) от 1 до 8: "; cin >> positionA.first >> positionA.second;
	cout << "Введите координаты B(столбец,ряд) от 1 до 8: "; cin >> positionB.first >> positionB.second;
	cout << "Выберите условие от 1 до 5: "; cin >> t;
	if (t > 5) { return 0; }

	switch (t)
	{
	case 1: if (positionA.first == positionB.first || positionA.second == positionB.second) { cout << "Ладья бьет фигуру"; break; }
				else { cout << "Ладья не бьет по фигуре"; break; }

	case 2: if (abs(positionA.first - positionB.first) == abs(positionA.second - positionB.second)) { cout << "Слон бьет фигуру"; break; }
		  else { cout << "Слон не бьет по фигуре"; break; }

	case 3: if (abs(positionA.first - positionB.first) < 2 && abs(positionA.second - positionB.second) < 2) { cout << "Король попадёт за один ход на требуемое поле"; break; }
		  else { cout << "Чтобы попасть на требуемое поле королю нужно более одного хода"; break; }

	case 4: if (abs(positionA.first - positionB.first) == abs(positionA.second - positionB.second) || positionA.first == positionB.first || positionA.second == positionB.second) { cout << "Ферзь бьет фигуру"; break; }
		  else { cout << "Ферзь не бьет фигуру"; break; }

	case 5: if ( (positionA.second == 2 && positionB.second == 4 || positionB.second - positionA.second == 1) && positionA.first == positionB.first) { cout << "Пешка может попасть на данное поле за 1 ход"; break; }
		  else  if (positionB.second - positionA.second == 1 && abs(positionA.first - positionB.first) == 1) { cout << "Пешка может попасть на данное поле за 1 ход, при том что она съест фигуру на данном поле"; break; }
		  else { cout << "Пешка не может попасть на данное поле"; break; }
	}
	
}