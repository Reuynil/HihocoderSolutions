#include<iostream>
#include<queue>

using namespace std;

int N, M, T;
int c[1002][1002];
int path[1002];

int findAugmentPath()
{
	bool visited[1002];
	for (int i = 0; i <= T; ++i)
		visited[i] = false;
	int capacity[1002];

	queue<int> q;
	q.push(0);
	visited[0] = true;
	capacity[0] = 0x7fffffff;
	path[0] = -1;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		if (u == T)
			return capacity[u];

		for (int v = 0; v <= T; ++v)
		{
			if (!visited[v] && c[u][v] > 0)
			{
				q.push(v);
				visited[v] = true;
				path[v] = u;
				capacity[v] = capacity[u] < c[u][v] ? capacity[u] : c[u][v];
			}
		}
	}

	return 0;
}

int main()
{
	cin >> N >> M;
	T = 2 * N + 1;
	for (int i = 0; i <= T; ++i)
	{
		for (int j = 0; j <= T; ++j)
		{
			if (i == 0 && j >= 1 && j <= N)
				c[i][j] = 1;
			else if (j == T && i <= 2 * N && i >= N + 1)
				c[i][j] = 1;
			else
				c[i][j] = 0;
		}
	}
	int u, v;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v;
		c[u][N + v] = 1;
	}
	int delta = findAugmentPath();
	while (delta>0)
	{
		int v = T;
		while (v != 0)
		{
			c[path[v]][v] -= delta;
			c[v][path[v]] += delta;
			v = path[v];
		}
		delta = findAugmentPath();
	}

	int num = 0;
	for (int i = N + 1; i <= 2 * N; ++i)
		if (c[i][T])
			num++;
	
	cout << num << endl;

	return 0;
}