#include<iostream>
#include<string>

using namespace std;

void compute_next(string patern,int next[], int len)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i<len)
	{
		if (j == -1 || patern[i] == patern[j])
		{
			j++;
			i++;
			next[j] = i;
		}
		else
		{
			j = next[j];
		}
	}

}

bool KMP(string p, string t, int next[])
{
	int pl = p.length();
	int tl = t.length();
	return false;
}

int main()
{
	int num;
	cin >> num;
	while (num--)
	{
		string patern, target;
		cin >> patern >> target;
		int len = patern.length();
		int* next = new int[len];
		compute_next(patern, next, len);
		for (int i = 0; i < len; i++)
		{
			cout << next[i] << endl;
		}
		//delete[] next;
	}
	return 0;
}