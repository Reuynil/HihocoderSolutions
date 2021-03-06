#pragma warning(disable:4996)

#include <algorithm>
#include <cstdio>
#define mx 1000001

using namespace std;

int MIN[mx][20], M[mx], n, m, l, r;

void rmq_init()
{
	for (int i = 1; i <= n; i++)
	{
		MIN[i][0] = M[i-1];
	}
	for (int j = 1; (1 << j) <= n; j++)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			MIN[i][j] = min(MIN[i][j-1], MIN[i + (1 << (j - 1))][j-1]);
		}
	}
}

int ask(int l, int r)
{
	int k = 0;
	while ((1 << (k + 1)) <= r - l + 1)
	{
		k++;
	}
	return min(MIN[l][k], MIN[r - (1 << k) + 1][k]);
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &M[i]);
		}
		rmq_init();
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &l, &r);
			printf("%d \n",ask(l, r));
		}
	}
	return 0;
}