#include<iostream>
#include<string>
#include<vector>

#define SRTLEN 1010
#define MOD 100007

using namespace std;

int d[SRTLEN][SRTLEN];
vector<int> res;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string a;
		cin >> a;
		int length = a.length();
		for (int i = 0; i < length; ++i)
		{
			d[i][i] = 1;
			if (i + 1 < length)
			{
				d[i + 1][i] = 0;
			}
		}
		for (int i = 1; i < length; ++i)
		{
			int k = i;
			for (int j = 0; k < length; ++j, ++k)
			{
				if (a[j] == a[k])
					d[j][k] = (d[j + 1][k] + d[j][k - 1] + 1) % MOD;
				else
					d[j][k] = ((d[j + 1][k] + d[j][k - 1] - d[j + 1][k - 1]) % MOD + MOD) % MOD;
			}
		}
		res.push_back(d[0][length - 1]);
	}
	int i = 1;
	for (auto iter : res)
	{
		cout << "Case #" << i << ": " << iter << endl;
		++i;
	}
	return 0;
}