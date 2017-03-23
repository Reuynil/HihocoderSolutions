#include<iostream>
#include<queue>
#include<string>

#define MAXN 810

using namespace std;

struct node
{
	int x;
	int y;
};

int visit[MAXN][MAXN];
int map[MAXN][MAXN];
int n, m;
queue<node> q;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string row;
		cin >> row;
		for (int j = 0; j < m; ++j)
		{
			int tmp = row[j] - '0';
			visit[i][j] = 0;
			if (tmp == 0)
			{
				map[i][j] = 0;
				visit[i][j] = 1;
				node p;
				p.x = i;
				p.y = j;
				q.push(p);
			}
		}
	}
	while (!q.empty())
	{
		node p = q.front();
		q.pop();
		int px = p.x;
		int py = p.y;
		if (px + 1 < n & visit[px + 1][py] == 0)
		{
			visit[px + 1][py] = 1;
			map[px + 1][py] = map[px][py] + 1;
			node u;
			u.x = px + 1;
			u.y = py;
			q.push(u);
		}
		if (py + 1 < m & visit[px][py + 1] == 0)
		{
			visit[px][py + 1] = 1;
			map[px][py + 1] = map[px][py] + 1;
			node u;
			u.x = px;
			u.y = py + 1;
			q.push(u);
		}
		if (px - 1 >= 0 & visit[px - 1][py] == 0)
		{
			visit[px - 1][py] = 1;
			map[px - 1][py] = map[px][py] + 1;
			node u;
			u.x = px - 1;
			u.y = py;
			q.push(u);
		}
		if (py - 1 >= 0 & visit[px][py - 1] == 0)
		{
			visit[px][py - 1] = 1;
			map[px][py - 1] = map[px][py] + 1;
			node u;
			u.x = px;
			u.y = py - 1;
			q.push(u);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}