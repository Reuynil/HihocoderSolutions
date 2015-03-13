#include <iostream>

using namespace std;

int main()
{
	int num;
	int data[100][100];
	int value[100][100];
	cin >> num;
	for (int i = 0; i<num; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cin >> data[i][j];
		}
	}
	value[0][0] = data[0][0];
	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)
			{
				value[i][j] = value[i - 1][j] + data[i][j];
			}
			else if (j == i)
			{
				value[i][j] = value[i - 1][j - 1] + data[i][j];
			}
			else
			{
				int max = (value[i - 1][j - 1] > value[i - 1][j] ? value[i - 1][j - 1] : value[i - 1][j]);
				value[i][j] = max + data[i][j];
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			if (temp < value[i][j])
			{
				temp = value[i][j];
			}
		}
	}
	cout << temp << endl;
	return 0;
}