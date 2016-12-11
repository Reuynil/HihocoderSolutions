#include<iostream>

using namespace std;

int N, M, T;
int c[402][402];
int path[402];

int findAugmentPath()
{
	bool visited[402];
	for (int i = 0; i <= T; ++i)
		visited[i] = false;
	int capacity[402];

	int q[402];
	int tail = 0;
	int head = -1;

	head++;
	tail++;
	q[head] = 0;
	path[0] = 0;
	visited[0] = true;
	capacity[0] = 0x7fffffff;

	while (head < tail)
	{
		int u = q[head];
		head++;
		
		if (u == T)
			return capacity[u];

		for (int v = 0; v <= T; ++v)
		{
			if (c[u][v] > 0 && !visited[v])
			{
				q[tail] = v;
				tail++;
				path[v] = u;
				visited[v] = true;
				capacity[v] = capacity[u] < c[u][v] ? capacity[u] : c[u][v];
			}
		}
	}
	return 0;
}

int main()
{
	cin >> N >> M;
	T = N + M + 1;

	for (int i = 0; i <= T; ++i)
		for (int j = 0; j <= T; ++j)
			c[i][j] = 0;

	int m, a, k, v;
	int activity = 0;
	for (int i = 1; i <= M; ++i)
	{
		cin >> m;
		c[i + N][T] = m;
	}
	for (int i = 1; i <= N; ++i)
	{
		cin >> a >> k;
		activity += a;
		c[0][i] = a;
		for (int j = 0; j < k; ++j)
		{
			cin >> v;
			c[i][N + v] = 0x7fffffff;
		}
	}
	int maxFlow = 0;
	int delta = findAugmentPath();
	while (delta)
	{
		int i = T;
		while (i > 0)
		{
			c[path[i]][i] -= delta;
			c[i][path[i]] += delta;
			i = path[i];
		}
		maxFlow += delta;
		delta = findAugmentPath();
	}
	cout << activity - maxFlow << endl;
	return 0;
}