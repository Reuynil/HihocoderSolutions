#include <iostream>

using namespace std;

double matrix[1000][500];
double value[500];
int n, m;	// n means column and m means row.

//return 0: no solution
//return 1: one solution
//return 2: many solutions
int solution()
{
	// ����������Ǿ���
	for (int i = 0;i < n;i++)
	{
		int j = 0;
		if (matrix[i][i] == 0)
		{
			for (j = i + 1;j < m;j++)
			{
				if (matrix[j][i] != 0)
				{
					for (int k = 0;k <= n;k++)
					{
						double temp = 0;
						temp = matrix[i][k];
						matrix[i][k] = matrix[j][k];
						matrix[j][k] = temp;
					}
				}
				break;
			}
		}
		// �������
		if (j == m)
			return 2;
		// ������i+1�е���M�еĵ�i��
		for (j = i + 1;j < m;j++)
		{
			double cofficient = matrix[j][i] / matrix[i][i];
			for (int k = 0;k < n + 1;k++)
			{
				matrix[j][k] = matrix[j][k] - matrix[i][k] * cofficient;
			}
		}
	}
	// ����Ƿ��޽⣬������ 0 = x �����
	for (int i = 0;i < m;i++)
	{
		int j = 0;
		for (;j < n;j++)
		{
			if (matrix[i][j] != 0)
			{
				break;	// �з���ֵ���˳�
			}
		}
		if (j == n&&matrix[i][n] != 0)
		{
			return 0;	// ���� 0 = x �����
		}
	}
	
	for (int i = n - 1;i >= 0;i--)
	{
		for (int j = i + 1;j < n;j++)
		{
			matrix[i][n] = matrix[i][n] - matrix[i][j] * value[j];
			matrix[i][j] = 0;
		}
		value[i] = matrix[i][n] / matrix[i][i];
	}

	return 1;
}

int main()
{

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			cin >> matrix[i][j];
		}
	}
	int res = solution();
	if (res == 0)
	{
		cout << "No solutions" << endl;
	}
	else if (res == 2)
	{
		cout << "Many solutions" << endl;
	}
	else 
	{
		for (int i = 0;i < n;i++)
		{
			cout << (int)(value[i] + 0.5) << endl;
		}
	}
	return 0;
}