#include<iostream>
#include<string>
#include<map>

#define N 20000

using namespace std;

int main()
{
	map<string, int> lastVist;
	string history[N];
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> history[i];
	}
	int s = 1;
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		string url = history[i];
		int last_vist = lastVist[url];
		if (last_vist >= s && last_vist <= i)
		{
			cout << "Cache" << endl;
		}
		else
		{
			count++;
			if (count > m)
			{
				s++;
			}
			cout << "Internet" << endl;
		}
		lastVist[url] = i;
		while (lastVist[history[s]] != s)
		{
			s++;
		}
	}
	return 0;
}