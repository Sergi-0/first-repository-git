#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string f2(string g) // ^
{
	int k, l;
	
	string numbers = "1234567890.";

	while (g.find("^") != -1)
	{
	string fix = "";
	string number = "";
	string degree;
	degree = g[g.find("^") + 1];
	l = g.find("^") + 1;

		for (int i = g.find("^") - 1; i >= 0; --i)
		{
			if (numbers.find(g[i]) == -1) break;
			k = i;
			number = g[i] + number;
		}

		for (int i = g.find("^") + 2; i <= g.length(); ++i)
		{
			if (numbers.find(g[i]) == -1) break;
			l = i;
			degree = degree + g[i];
		}

		fix = to_string( pow( atof( number.c_str()), atof(degree.c_str()) ) ) ;
		g.replace(k, l - k + 1, fix);
	}
	return g;
}

string f3(string g) // *
{
	int k, l;

	string numbers = "1234567890.";

	while (g.find("*") != -1)
	{
		string fix = "";
		string number1 = "";
		string number2;
		number2 = g[g.find("*") + 1];
		l = g.find("*") + 1;

		for (int i = g.find("*") - 1; i >= 0; --i)
		{
			if (numbers.find(g[i]) == -1)
			{
				if (g[i] == '-')
				{
					k = i;
					number1 = g[i] + number1;
				}
				break;
			}
			k = i;
			number1 = g[i] + number1;
		}

		for (int i = g.find("*") + 2; i <= g.length(); ++i)
		{
			if (numbers.find(g[i]) == -1) break;	
			l = i;
			number2 = number2 + g[i];
		}

		fix = to_string(atof(number1.c_str()) * atof(number2.c_str()));
		g.replace(k, l - k + 1, fix);
	}
	return g;
}

string f4(string g) // /
{
	int k, l;

	string numbers = "1234567890.";

	while (g.find("/") != -1)
	{
		string fix = "";
		string number1 = "";
		string number2;
		number2 = g[g.find("/") + 1];
		l = g.find("/") + 1;

		for (int i = g.find("/") - 1; i >= 0; --i)
		{
			if (numbers.find(g[i]) == -1)
			{
				if (g[i] == '-')
				{
					k = i;
					number1 = g[i] + number1;
				}
				break;
			}
			k = i;
			number1 = g[i] + number1;
		}

		for (int i = g.find("/") + 2; i <= g.length(); ++i)
		{
			if (numbers.find(g[i]) == -1) break;
			l = i;
			number2 = number2 + g[i];
		}

		fix = to_string(atof(number1.c_str()) / atof(number2.c_str()));
		g.replace(k, l - k + 1, fix);
	}
	return g;
}

string f6(string g) // +
{
	int k, l;

	string numbers = "1234567890.";

	while (g.find("+") != -1)
	{
		string fix = "";
		string number1 = "";
		string number2;
		number2 = g[g.find("+") + 1];
		l = g.find("+") + 1;

		for (int i = g.find("+") - 1; i >= 0; --i)
		{
			if (numbers.find(g[i]) == -1)
			{
				if (g[i] == '-')
				{
					k = i;
					number1 = g[i] + number1;
				}
				break;
			}
			k = i;
			number1 = g[i] + number1;
		}

		for (int i = g.find("+") + 2; i <= g.length(); ++i)
		{
			if (numbers.find(g[i]) == -1) break;
			l = i;
			number2 = number2 + g[i];
		}

		fix = to_string(atof(number1.c_str()) + atof(number2.c_str()));
		g.replace(k, l - k + 1, fix);
	}
	return g;
}

string f5(string g) // обработка строки - под f6
{
	string f = "";

	while (g.find("--") != -1) g.replace(g.find("--"), 2, "+");

	if (g[0] == '+') g.erase(0, 1);

	for (int i = 0; i <= g.length(); ++i)
	{
		if (g[i] == '-')
		{ 
			f = f + '+' + g[i]; 
		}

		else

		{
			f = f + g[i];
		}
	} 
	while (f.find("++") != -1) f.replace(f.find("++"), 2, "+");
	if (f[0] == '+') f.erase(0, 1);

	return f;
}

string f1(string s) // ()
{
	int k;
	while (s.find(")") != -1)
	{
		string a = "";
		k = s.find(")");
		for (int i = s.find(")") - 1; i >= 0; --i)
		{	
			if (s[i] == '(') break;
			k = i;
			a = s[i] + a;
		}
		s.replace(k - 1, s.find(")") - k + 2, f6(f5(f4(f3(f2(a))))));
	}
	s = f6(f5(f4(f3(f2(s)))));
	return s;
}

int main()
{
string a;
cin >> a;
while (a != "stop")
{
	cout << f1(a) << endl;
	cin >> a;
}

}