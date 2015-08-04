#include <iostream>
#include <string>

#define COFFICIENT matrix[i][i] / matrix[j][i]

using namespace std;

int matrix[1000][501];
int price[501];
int n, m;	// n means column and m means row.

void triangleMatrix()
{
	for (int i = 0;i < m; i++)
	{
		for (int j = i + 1;j < m;j++)
		{
			if (matrix[j][i] == 0)
				continue;
			for (int k = 0;k < n;k++)
			{
				matrix[j][k] = matrix[j][k] * COFFICIENT - matrix[i][k];
			}
		}
	}
}

string judge(int& r)
{
	string reslut;
	int i = m - 1;
	for (;i >= 0;i--)
	{
		int j = 0;
		for (;j < n && matrix[i][j] == 0;j++);
		if (j == n - 1)
		{
			if (matrix[i][j] != matrix[i][j])
				return "NoSolution";
		}
		if (j > n - 1)
		{
			return "ManySolutions";
		}
	}
	r = i;
	return "OneSolution";
}

void solution(const int& r)
{
	int i = r;
	for (;i >= 0;i--)
	{

	}
}

int main()
{
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			cin >> matrix[i][j];
		}
	}

		return 0;
}