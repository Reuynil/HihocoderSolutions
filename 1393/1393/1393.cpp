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

//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//#define MAX 205
//#define MAXCF 101
//#define min(a,b) (a)>(b)?(b):(a)
//
//using namespace std;
//
//int cf[MAX][MAX];//存储图
//int queue[MAX];//搜索队列
//int path[MAX];//保存路径
//int capacity[MAX];//流量数组，保存经过该点的最小流量
//bool visited[MAX];//记录访问数组
//
//int findAugmentPath(int T)
//{
//	int i = 0, tail = 0;
//	memset(visited, 0, sizeof(visited));
//
//	queue[tail] = 1;//将源点加入队列
//	capacity[1] = MAXCF;
//	visited[1] = true;
//	while (i <= tail)
//	{
//		int u = queue[i];
//		if (u == T)
//			return capacity[T];//找到一条增广路径，返回该路径最小流量
//		for (int v = 2; v <= T; v++)
//		{
//			if (!visited[v] && cf[u][v] > 0)
//			{
//				path[v] = u;
//				capacity[v] = min(cf[u][v], capacity[u]);//记录路径上的最小残余流量
//				visited[v] = true;
//				tail++;
//				queue[tail] = v;
//			}
//		}
//		i++;
//	}
//	return 0;
//}
//
//void modifyGraph(int T)
//{
//	int flow = capacity[T];
//	int now = T;
//	cout << "path: ";
//	while (now != 1)
//	{
//		cout << now << ' ';
//		int fa = path[now];
//		cf[fa][now] -= flow;
//		cf[now][fa] += flow;
//		now = fa;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int T;
//	int N, M;
//	int i, j;
//	int temp;
//	int m[MAX];
//	int a[MAX], b[MAX];
//	cin >> T;
//
//	while (T--)
//	{
//		cin >> N >> M;
//		int S = 1;
//		int E = S + N + M + 1;
//		int result = 0;
//		memset(cf, 0, sizeof(cf));
//		for (i = 0; i < M; ++i)
//		{
//			cin >> m[i];
//			cf[S + N + i + 1][E] = m[i];
//			result += m[i];
//		}
//
//		for (i = 0; i < N; ++i)
//		{
//			cin >> a[i] >> b[i];
//			cf[S][S + i + 1] = a[i];
//			for (j = 0; j < b[i]; ++j)
//			{
//				cin >> temp;
//				cf[S + i + 1][S + N + temp] = 1;
//			}
//		}
//		int maxFlow = 0;
//		int delta = 0;
//		while (delta = findAugmentPath(E))
//		{
//			maxFlow += delta;
//			modifyGraph(E);
//		}
//		if (maxFlow == result)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//
//	}
//	return 0;
//}
//
//

