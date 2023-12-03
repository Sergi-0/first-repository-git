#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Book
{
	string Author;
	string Title;
	int Year;
};

void saveToFile(const string& filename, const vector<Book>& data)
{
	ofstream file(filename);
	if (file.is_open()) for (const auto& i : data) file << i.Author << "/" << i.Title << "/" << i.Year << " " << endl;
	file.close();
}

void loadFromFile(const string& filename, vector<Book>& outData)
{
	string k,a;
	Book b;
	ifstream file(filename);
	if (file.is_open()) {
		while (getline(file, a)) {
			stringstream t(a);
			getline(t, b.Author, '/');
			getline(t, b.Title, '/');
			getline(t, k, ' ');
			b.Year = atoi(k.c_str());
			outData.push_back(b);
		}
	}
	file.close();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Book a, b, c;
	a.Author = "Пушкин"; a.Title = "Сказка о рыбаке и рыбке"; a.Year = 1800;
	b.Author = "Экзюпери"; b.Title = "Маленький принц"; b.Year = 1750;
	c.Author = "Хемингуэй"; c.Title = "Старик и море"; c.Year = 1700;

	vector<Book> data = {a,b,c};
	vector<Book> outData;

	saveToFile("kukuhapoehala.txt", data);
	loadFromFile("kukuhapoehala.txt", outData);

	for (int i = 0; i < 3; ++i) {
		cout << outData[i].Author << " / " << outData[i].Title << " / " << outData[i].Year << endl;
	}
}