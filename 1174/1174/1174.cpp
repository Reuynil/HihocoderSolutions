#include<iostream>
#include<queue>

#define MAXM 500001

using std::cin;
using std::cout;
using std::endl;
using std::queue;

int head[MAXM];
int p[MAXM];
int next[MAXM];
int degree[MAXM];
int edgecnt;

void addEdge(int u, int v)
{
	++edgecnt;
	p[edgecnt] = v;
	next[edgecnt] = head[u];
	head[u] = edgecnt;
}

int main()
{
	int t, n, m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;

		for (int i = 0; i <= m; i++)
		{
			head[i] = 0;
			p[i] = 0;
			next[i] = 0;
			degree[i] = 0;
		}
		edgecnt = 0;

		int u, v;
		queue<int> q;
		while (m--)
		{
			cin >> u >> v;
			addEdge(u, v);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = head[i]; j; j = next[j])
			{
				degree[p[j]]++;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (degree[i] == 0)
			{
				q.push(i);
			}
		}
		int pop_num = 0;
		while (!q.empty())
		{
			int h = q.front();
			q.pop();
			pop_num++;
			for (int i = head[h]; i; i = next[i])
			{
				degree[p[i]]--;
				if (degree[p[i]] == 0)
				{
					q.push(p[i]);
				}
			}
		}
		if (pop_num == n)
		{
			cout << "Correct" << endl;
		}
		else
		{
			cout << "Wrong" << endl;
		}
	}
	return 0;
}