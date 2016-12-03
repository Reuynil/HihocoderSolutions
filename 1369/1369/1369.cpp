#include<iostream>
#include<queue>

using namespace std;

int c[501][501];
int n, m;
int path[501];

int findAugmentPath()
{
	unsigned int capacity[501];
	bool visited[501];
	for (int i = 1; i <= 500; ++i)
		visited[i] = false;
	queue<int> q;

	q.push(1);
	capacity[1] = 0xffffffff;
	visited[1] = true;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 1; v <= n; ++v)
		{
			if (c[u][v] > 0 && !visited[v])
			{
				q.push(v);
				visited[v] = true;
				path[v] = u;
				capacity[v] = c[u][v] < capacity[u] ? c[u][v] : capacity[u];
				if (v == n)
				{
					return capacity[v];
				}
			}
		}
	}

	return 0;
}

void modifyGraph(int d)
{
	int i = n;
	while (i != 1)
	{
		c[path[i]][i] -= d;
		i = path[i];
	}
}

int main()
{
	for (int i = 0; i < 501; ++i)
		for (int j = 0; j < 501; ++j)
			c[i][j] = 0;

	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> w;
		c[u][v] += w;
	}

	int maxFlow = 0;
	int delta = 0;
	delta = findAugmentPath();
	while (delta > 0)
	{
		maxFlow = maxFlow + delta;
		modifyGraph(delta);
		delta = findAugmentPath();
	}

	cout << maxFlow << endl;
	return 0;
}