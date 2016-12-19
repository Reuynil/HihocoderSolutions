#include<iostream>
#include<string>

using namespace std;

int main()
{
	int N;
	string s;
	cin >> N >> s;
	int i = 0;
	int a;
	while (i < N)
	{
		if (s[i] == 'H')
		{
			if (i == 0)
				a = i + 1;
			else
				a = a ^ (i + 1);
		}
		i++;
	}
	if (a)
		cout << "Alice" << endl;
	else
		cout << "Bob" << endl;
	return 0;
}