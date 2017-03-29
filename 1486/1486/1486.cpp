#include<iostream>
#include<cstring>

#define N 1100

using namespace std;

int dp[N][1 << 11];

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, m;
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		int status = 1 << m;
		memset(dp, -1, sizeof(dp));	//注意此处初始值为-1，代表该状态不可达
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++)
		{
			int s, v, mask = 0;
			cin >> v >> s;
			for (int j = 0; j < s; j++)
			{
				int x;
				cin >> x;
				x--;
				mask |= 1 << x;
			}
			for (int j = 0; j < status; j++)
			{
				if (~dp[i - 1][j])	//-1的反码是0，意味着只有dp[i - 1][j]是一个可达状态时，我们才进行讨论。
				{
					/* 在dp[i - 1][j]是一个可达状态的前提下，我们有两种方案：
					 1.我们决定取该物品，这会使得状态进入dp[i][j^mask]，在这种状态下，我们有两种可能:
						1.最大总价值等于不取该物品时的最大价值，加上该物品的价值，此时需要更改dp[i][j^mask]
						2.已经存在另外一种方案，使得总价值大于取该物品的方案，此时不需要更改dp[i][j^mask]
					 2.我们决定不取该物品，这意味着状态保留在dp[i][j]，在这种状态下，我们还是有两种可能：
						1.已经存在一种不取该物品方案，使得总价值最大，此时dp[i][j] = dp[i-1][j]
						2.上边取该物品的决定已经修改了dp[i][j]，而且修改后的总价值更大，此时不需要修改dp[i][j]
					 */
					dp[i][j^mask] = max(dp[i][j^mask], dp[i - 1][j] + v);
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				}
			}
		}
		cout << max(dp[n][status - 1], 0) << endl;
	}

	return 0;
}