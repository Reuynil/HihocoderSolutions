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
		memset(dp, -1, sizeof(dp));	//ע��˴���ʼֵΪ-1�������״̬���ɴ�
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
				if (~dp[i - 1][j])	//-1�ķ�����0����ζ��ֻ��dp[i - 1][j]��һ���ɴ�״̬ʱ�����ǲŽ������ۡ�
				{
					/* ��dp[i - 1][j]��һ���ɴ�״̬��ǰ���£����������ַ�����
					 1.���Ǿ���ȡ����Ʒ�����ʹ��״̬����dp[i][j^mask]��������״̬�£����������ֿ���:
						1.����ܼ�ֵ���ڲ�ȡ����Ʒʱ������ֵ�����ϸ���Ʒ�ļ�ֵ����ʱ��Ҫ����dp[i][j^mask]
						2.�Ѿ���������һ�ַ�����ʹ���ܼ�ֵ����ȡ����Ʒ�ķ�������ʱ����Ҫ����dp[i][j^mask]
					 2.���Ǿ�����ȡ����Ʒ������ζ��״̬������dp[i][j]��������״̬�£����ǻ��������ֿ��ܣ�
						1.�Ѿ�����һ�ֲ�ȡ����Ʒ������ʹ���ܼ�ֵ��󣬴�ʱdp[i][j] = dp[i-1][j]
						2.�ϱ�ȡ����Ʒ�ľ����Ѿ��޸���dp[i][j]�������޸ĺ���ܼ�ֵ���󣬴�ʱ����Ҫ�޸�dp[i][j]
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