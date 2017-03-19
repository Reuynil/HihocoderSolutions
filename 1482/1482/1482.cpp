#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int m = pow(10, 9) + 7;
	int n;
	long long r[2][6];
	cin >> n;
	r[0][0] = r[0][1] = r[0][2] = 1;
	r[0][3] = r[0][4] = r[0][5] = 0;
	for (int i = 1; i < n; ++i)
	{
		r[1][0] = r[0][0] + r[0][2] + r[0][5];
		r[1][1] = r[0][0] + r[0][1] + r[0][2] + r[0][3] + r[0][4] + r[0][5];
		r[1][2] = r[0][0];
		r[1][3] = r[0][1];
		r[1][4] = r[0][3];
		r[1][5] = r[0][2];
		for (int j = 0; j < 6; ++j)
			r[0][j] = r[1][j] % m;
	}
	long long res = 0;
	for (int i = 0; i < 6; ++i)
		res = (res + r[0][i]) % m;
	cout << res << endl;
	return 0;
}