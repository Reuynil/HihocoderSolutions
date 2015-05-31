#include<iostream>
#include<string>

#define MAX 10005

using namespace std;

void compute_next(const string& patern, int next[])
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i<patern.length())
	{
		if (j == -1 || patern[i] == patern[j])
		{
			j++;
			i++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}

}

int KMP(const string& p, const string& t, int next[])
{
	int pl = p.length();
	int tl = t.length();
	int res = 0, j = 0;
	for (int i = 0; i < tl; i++)
	{
		while (j>0 && t[i] != p[j])
		{
			j = next[j];
		}
		if (j == -1 || t[i] == p[j])
		{
			j++;
		}
		if (j == pl)
		{
			j = next[j];
			res++;
		}
	}
	return res;
}

int main()
{
	int num;
	cin >> num;
	while (num--)
	{
		string patern, target;
		cin >> patern >> target;
		int next[MAX];
		compute_next(patern, next);
		cout << KMP(patern, target, next) << endl;
	}
	return 0;
}