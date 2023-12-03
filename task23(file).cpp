#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void saveToFile(const string& filename, const vector<string>& data)
{
	ofstream file(filename);
	if (file.is_open()) for (const string& i : data) file << i << endl;
	file.close();
}

void loadFromFile(const string& filename, vector<string>& outData)
{
	string a;
	ifstream file(filename);
	if (file.is_open()) while (file >> a) outData.push_back(a);
	file.close();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	vector<string> data = { "черепаха", "заяц", "утка" };
	vector<string> outData;
	saveToFile("kukuhapoehala.txt", data);
	loadFromFile("kukuhapoehala.txt", outData);
	cout << outData[0] << outData[1] << outData[2];
}
