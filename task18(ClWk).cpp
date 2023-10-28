#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

struct Student
{
	string name;
	int age, math, phys, eng;
	double average_mark;
};

class Group
{
private:
	vector<Student> students;
	int count;
	double av_age_gr, sum;
	string name;
public:
	Group()
	{
		Student st;

		cout << "Введите количество студентов в группе: "; cin >> count;
		cout << "Введите название группы: "; cin >> name;
		cout << endl;

		sum = 0;

		for (int i = 0; i < count; ++i)
		{	
			cout << "Введите в строку имя " << i+1 << " студента, его возраст, оценку по математике, физике и английскому : ";
			cin >> st.name >> st.age >> st.math >> st.phys >> st.eng;
			st.average_mark = (st.math + st.phys + st.eng) / 3.0;
			sum += st.age;
			students.push_back(st);
		}

		av_age_gr = sum / count;
	}

	void prnt()
	{
		for (int i = 0; i < count; ++i)
		{
			cout << "Имя " << i + 1 << " студента: " << students[i].name << endl;
			cout << "Возраст " << i + 1 << " студента: " << students[i].age << endl;
			cout << "Группа: " << name << endl;
			cout << "Средняя оценка по 3 предметам " << i + 1 << " студента: " << students[i].average_mark << endl << endl;
		}

		cout << endl << "Средний возраст группы " << name << ": " << av_age_gr << endl;;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Group Gr;
	cout << endl;
	Gr.prnt();
}