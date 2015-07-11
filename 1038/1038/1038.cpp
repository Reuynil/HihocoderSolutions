#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[100000], need[501], value[501];

int main()
{
	memset(dp, 0, sizeof(int) * 100000);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> need[i] >> value[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = M-1; j >= need[i]; j--)
		{
			dp[j] = max(dp[j - need[i]] + value[i], dp[j]);
		}
	}
	cout << dp[M - 1] << endl;
	return 0;
}