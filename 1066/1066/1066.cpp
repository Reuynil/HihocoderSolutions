// I have try using list provided by STL instead of array, but got a TLE.

#include<iostream>
#include<string>

#define MAX 10000

using namespace std;

string person[MAX];
int represent[MAX];
int num = 0;

int findByName(string name)
{
	if (num == 0)
		return -1;
	for (int i = 0; i < num;i++)
		if (person[i] == name)
			return i;
	return -1;//return -1 if not found.
}

int findRepresent(int x)
{
	if (represent[x] == x)
	{
		return x;
	}
	else
	{
		int p = findRepresent(represent[x]);
		represent[x] = p;
		return p;
	} 
}

void add(string name1, string name2)
{
	// detemines whether the person is exist. If not, add; otherwise, find his represent.
	int iter1 = findByName(name1);
	if (iter1 == -1)
	{
		person[num] = name1;
		represent[num] = num;
		iter1 = num;
		num++;
	}
	else
	{
		iter1 = findRepresent(iter1);
	}
	int iter2 = findByName(name2);
	if (iter2 == -1)
	{
		person[num] = name2;
		represent[num] = num;
		iter2 = num;
		num++;
	}
	else
	{
		iter2 = findRepresent(iter2);
	}
	represent[iter1] = iter2;
}

bool judge(string name1,string name2)
{
	int iter1 = findByName(name1);
	int iter2 = findByName(name2);
	if (iter1==-1||iter2==-1)
		return false;
	if (findRepresent(iter1) == findRepresent(iter2))
		return true;
	return false;
}

int main()
{
	int num;
	cin >> num;
	while (num--)
	{
		int op;
		string name1, name2;
		cin >> op >> name1 >> name2;
		if (op == 0)
		{
			add(name1, name2);
		}
		else
		{
			if (judge(name1, name2))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
	}
	return 0;
}