#include <iostream>
using namespace std;

struct Matrix
{
	int** data = nullptr;
	size_t n = 0u;
	size_t m = 0u;
};

void Construct(Matrix& out, size_t n, size_t m)
{
	out.n = n;
	out.m = m;
	out.data = new int* [n];
	for (size_t i = 0; i < n; ++i)
	{
		out.data[i] = new int[m];
		for (size_t j = 0; j < m; ++j) out.data[i][j] = 0;
	}
};

void Rand(Matrix& out, size_t n, size_t m)
{
	out.n = n;
	out.m = m;
	out.data = new int* [n];
	for (size_t i = 0; i < n; ++i)
	{
		out.data[i] = new int[m];
		for (size_t j = 0; j < m; ++j) out.data[i][j] = rand() % 100;
	}
};

void Destruct(Matrix& in)
{
	for (size_t i = 0; i < in.n; ++i) delete[] in.data[i];
	delete[] in.data;
};

Matrix Copy(const Matrix& matrix)
{
	Matrix m2;
	m2.n = matrix.n;
	m2.m = matrix.m;
	m2.data = new int* [matrix.n];

	for (size_t i = 0; i < matrix.n; ++i)
	{
		m2.data[i] = new int[matrix.m];
		for (size_t j = 0; j < matrix.m; ++j) m2.data[i][j] = matrix.data[i][j];
	}

	return m2;
};

Matrix Add(const Matrix& a, const Matrix b)
{
	Matrix m3;
	if (a.n == b.n && a.m == b.m)
	{
		
		m3.n = a.n;
		m3.m = a.m;
		m3.data = new int* [a.n];
		for (size_t i = 0; i < a.n; ++i)
		{
			m3.data[i] = new int[a.m];
			for (size_t j = 0; j < a.m; ++j) m3.data[i][j] = a.data[i][j] + b.data[i][j];
		}
	}

	else

	{
		m3.data = nullptr;
		m3.n = 0u;
		m3.m = 0u;
	}

	return m3;
};

Matrix Sub(const Matrix& a, const Matrix b)
{
	Matrix m3;
	if (a.n == b.n && a.m == b.m)
	{

		m3.n = a.n;
		m3.m = a.m;
		m3.data = new int* [a.n];
		for (size_t i = 0; i < a.n; ++i)
		{
			m3.data[i] = new int[a.m];
			for (size_t j = 0; j < a.m; ++j) m3.data[i][j] = a.data[i][j] - b.data[i][j];
		}
	}

	else

	{
		m3.data = nullptr;
		m3.n = 0u;
		m3.m = 0u;
	}

	return m3;
};

Matrix Mult(const Matrix& a, const Matrix& b)
{
	Matrix m3;
	if (a.n == b.m)
	{
		Construct(m3, b.n, a.m);
		for (size_t i = 0; i < b.n; ++i)
		{
			for (size_t j = 0; j < a.m; ++j)
			{
				for (size_t k = 0; k < a.n; ++k)
				{
					m3.data[i][j] += a.data[k][i] * b.data[j][k];
				}
			}
		}
	}

	else

	{
		m3.data = nullptr;
		m3.n = 0u;
		m3.m = 0u;
	}

	return m3;
}

void Transposition(Matrix& matrix)
{
	Matrix tr;
	Construct(tr, matrix.m, matrix.n);

	for (size_t i = 0; i < matrix.m; i++)
	{
		for (size_t j = 0; j < matrix.n; j++)
		{
			tr.data[i][j] = matrix.data[j][i];
			cout << tr.data[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	Matrix m1;
	Rand(m1, 5, 6);
	Transposition(m1);
}
