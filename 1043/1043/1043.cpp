#include<iostream>
#include<cstring>

using namespace std;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	unsigned int weight[510], value[510], tab[100010];
	memset(tab, 0, sizeof(tab));
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> weight[i] >> value[i];
	for (unsigned int i = 0; i < n; ++i)
	{
		for (unsigned int j = 0; j <= m; ++j)
		{
			if (j < weight[i])
				tab[j] = tab[j];
			else
				tab[j] = max(tab[j], tab[j - weight[i]] + value[i]);
		}
	}
	cout << tab[m] << endl;
	return 0;
}