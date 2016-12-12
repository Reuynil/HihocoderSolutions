#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int N, M, K;
	queue<int> process;
	int total_virus = 0;

	cin >> N >> M >> K;
	vector<int> *network = new vector<int>[N + 1];
	int *degree = new int[N + 1];
	int *virus = new int[N + 1];

	for (int i = 1; i <= N; ++i)
	{
		degree[i] = 0;
		virus[i] = 0;
	}
	int j, k, l;
	for (int i = 0; i < K; ++i)
	{
		cin >> j;
		virus[j] = 1;
		total_virus++;
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> k >> l;
		network[k].push_back(l);
		degree[l]++;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (degree[i] == 0)
		{
			process.push(i);
		}
	}
	while (!process.empty())
	{
		int u = process.front();
		process.pop();
		for (auto &i : network[u])
		{
			if (virus[u] > 0)
			{
				virus[i] += virus[u];
				virus[i] %= 142857;
				total_virus += virus[u];
				total_virus %= 142857;
			}
			degree[i]--;
			if (degree[i] == 0)
				process.push(i);
		}
	}
	cout << total_virus << endl;
	delete[] network;
	delete[] degree;
	delete[] virus;
	return 0;
}