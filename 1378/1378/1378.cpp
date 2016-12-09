#include<iostream>
#include<queue>

using namespace std;

int c[501][501];
int n, m;
int path[501];
int orign_c[501][501];
bool visited[501];

int findAugmentPath()
{
	unsigned int capacity[501];
	for (int i = 1; i <= n; ++i)
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

int main()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			c[i][j] = 0;
			orign_c[i][j] = 0;
		}
	}

	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> w;
		c[u][v] += w;
		orign_c[u][v] += w;
	}

	int delta = 0;
	delta = findAugmentPath();
	while (delta > 0)
	{
		int i = n;
		while (i != 1)
		{
			c[path[i]][i] -= delta;
			i = path[i];
		}
		delta = findAugmentPath();
	}

	int smallestCapacity = 0;
	int num = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i] == true)
		{
			num++;
			for (int j = 1; j <= n; ++j)
				if (orign_c[i][j] > 0 && !visited[j])
					smallestCapacity += orign_c[i][j];
		}
	}

	cout << smallestCapacity << " " << num << endl;
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i])
		{
			cout << i << " ";
		}
	}

	return 0;
}