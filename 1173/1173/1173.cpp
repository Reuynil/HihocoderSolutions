#include<iostream>

using namespace std;

int sg[20001];
int N;
int stone[101];
int temp[20001];

int getSG(int i)
{
	for (int j = 0; j <= i + 1; ++j)
		temp[j] = 0;

	if (i == 0)
		return  0;
	else
	{
		for (int j = 0; j <= i - 1; ++j)
			temp[sg[j]] = 1;
		for (int j = 1; j <= i - 1; ++j)
			temp[sg[j] ^ sg[i - j]] = 1;
		for (int j = 0; j <= i + 1; ++j)
			if (!temp[j])
				return j;
	}
}

int main()
{
	cin >> N;
	int max = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> stone[i];
		max = stone[i] > max ? stone[i] : max;
	}
	for (int i = 0; i <= max; ++i)
		sg[i] = getSG(i);

	int res;
	for (int i = 0; i < N; ++i)
	{
		if (i == 0)
			res = sg[stone[i]];
		else
			res = res ^ sg[stone[i]];
	}
	if (res)
		cout << "Alice" << endl;
	else
		cout << "Bob" << endl;
	return 0;
}