#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily = 3,
    Good = 4,
    Excellent = 5
};

struct Student
{
    string Name;
    int Year;
    map<string, Score> RecordBook; // math physics language
};

using Groups = map<string, vector<Student>>;

void saveToFile(const string& filename, const Groups& groups)
{
    ofstream file(filename);
    if (file.is_open()) {
        cout << "Какую группу вы хотите сохранить в файл ?" << endl;
        string a;
        cin >> a;
        auto it = groups.find(a);

        file << a << ":" <<endl;
        for(const auto &i : it->second){
        file << i.Name << "/";
        for (const auto& t : i.RecordBook) file << t.first << " " << t.second << "/";
        file << i.Year << "." << endl;
        }
    }
    file.close();
}

void loadFromFile(const string& filename, Groups& outGroups) {
    ifstream file(filename);
    if (file.is_open()) {
        string a,k,l,f;
        vector<Student> b;
        Student c;
        getline(file, k, ':');
        
        while (getline(file, a)) {

            stringstream t(a);

            getline(t, c.Name, '/');

            getline(t, l, ' ');
            getline(t, f, '/');
            c.RecordBook.emplace(pair<string, Score> (l, Score(atof(f.c_str()))));
            getline(t, l, ' ');
            getline(t, f, '/');
            c.RecordBook.emplace(pair<string, Score>(l, Score(atof(f.c_str()))));
            getline(t, l, ' ');
            getline(t, f, '/');
            c.RecordBook.emplace(pair<string, Score>(l, Score(atof(f.c_str()))));

            getline(t, l, '.');
            c.Year = atoi(l.c_str());

            b.push_back(c);
        }

        outGroups.emplace(pair<string,vector<Student>>(k,b));
    }

}

int main()
{
    setlocale(LC_ALL, "Rus");
    Student a, b, c, d, e, f;

    a.Name = "Инокентий";
    a.Year = 23;
    a.RecordBook = { {"math",Good}, {"physics", Excellent}, {"language", Satisfactorily} };

    b.Name = "Евтодий";
    b.Year = 99;
    b.RecordBook = { {"math",Unsatisfactorily}, {"physics", Unsatisfactorily}, {"language", Satisfactorily} };

    c.Name = "Акакий";
    c.Year = 29;
    c.RecordBook = { {"math",Satisfactorily}, {"physics", Satisfactorily}, {"language", Good} };

    d.Name = "Магомед";
    d.Year = 45;
    d.RecordBook = { {"math",Unsatisfactorily}, {"physics", Unsatisfactorily}, {"language", Unsatisfactorily} };

    e.Name = "Люлякебаб";
    e.Year = 15;
    e.RecordBook = { {"math",Excellent}, {"physics", Excellent}, {"language", Excellent} };

    f.Name = "Ашот";
    f.Year = 21;
    f.RecordBook = { {"math",Unsatisfactorily}, {"physics", Unsatisfactorily}, {"language", Unsatisfactorily} };

    vector<Student> gr1 = { a,b,c };
    vector<Student> gr2 = { d,e,f };

    Groups groups = { {"IU8",gr1}, {"IU10", gr2} };
    Groups outGroups;

    saveToFile("privet.txt", groups);
}