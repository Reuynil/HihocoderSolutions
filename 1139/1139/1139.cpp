#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct edge
{
	int t;
	int w;
};
int N, M, K, T;
vector<edge> g[100001];

bool findPath(int max)
{
	int *path = new int[N + 1];
	for (int i = 0; i <= N; ++i)
	{
		path[i] = 0;
	}
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		if (u == T)
			return true;
		if (path[u] == K)
			continue;
		for (auto &w : g[u])
		{
			int v = w.t;
			if (path[v] || w.w > max)
				continue;
			path[v] = path[u] + 1;
			q.push(v);
		}
	}
	delete[] path;
	return false;
}

int main()
{
	cin >> N >> M >> K >> T;
	int L, R;
	int u, v, w;
	L = 0;
	R = 0;

	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v >> w;
		edge tmp;
		tmp.t = v;
		tmp.w = w;
		g[u].push_back(tmp);
		tmp.t = u;
		g[v].push_back(tmp);
		R = R > w ? R : w;
	}
	int mid;
	while (L + 1 < R)
	{
		mid = (L + R) / 2;
		if (findPath(mid))
			R = mid;
		else
			L = mid;
	}
	cout << R << endl;
	return 0;
}