#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, p, result = 0;
	string win;
	while (cin >> n)
	{
		for (int i = 0; i<n; i++)
		{
			cin >> p;
			result = result^p;
		}
		win = result ? "Alice" : "Bob";
		cout << win << endl;
	}
	return 0;
}