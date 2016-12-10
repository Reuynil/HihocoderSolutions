#include<iostream>
#include<queue>

using namespace std;

int c[205][205];
int path[205];
int T, t, M, N;

int findAugmentPath()
{
	unsigned int capacity[205];
	bool visited[205];
	for (int i = 0; i <= T; ++i)
		visited[i] = false;
	queue<int> q;

	q.push(0);
	capacity[0] = 0xffffffff;
	visited[0] = true;
	path[0] = -1;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v <= T; ++v)
		{
			if (c[u][v] > 0 && !visited[v])
			{
				q.push(v);
				visited[v] = true;
				capacity[v] = capacity[u] < c[u][v] ? capacity[u] : c[u][v];
				path[v] = u;
				if (v == T)
				{
					return capacity[v];
				}
			}
		}
	}

	return 0;
}

int judge()
{
	for (int i = N + 1; i <= M + N; ++i)
	{
		if (c[i][T] > 0)
		{
			cout << "No" << endl;
			return 1;
		}
	}
	cout << "Yes" << endl;
	return 0;
}


int main()
{
	cin >> t;
	while (t--)
	{
		cin >> N >> M;
		T = N + M + 1;
		for (int i = 0; i <= T; ++i)
			for (int j = 0; j <= T; ++j)
				c[i][j] = 0;

		for (int i = N + 1; i <= M + N; ++i)
			cin >> c[i][T];

		int temp, v;
		for (int i = 1; i <= N; ++i)
		{
			cin >> c[0][i] >> temp;
			for (int j = 0; j < temp; ++j)
			{
				cin >> v;
				c[i][v + N] = 1;
			}
		}

		int maxFlow = 0;
		int delta = findAugmentPath();
		while (delta > 0)
		{
			maxFlow += delta;
			int v = T;
			while (v != -1)
			{
				c[path[v]][v] -= delta;
				c[v][path[v]] += delta;
				v = path[v];
			}
			delta = findAugmentPath();
		}
		judge();
	}

	return 0;
}
