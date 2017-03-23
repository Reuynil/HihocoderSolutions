#include<iostream>

using namespace std;

int heap[100010];
int num;

int max(int a, int b, int c)
{
	int t = heap[a] > heap[b] ? a : b;
	if (c > num)
		return t;
	t = heap[t] > heap[c] ? t : c;
	return t;
}

void add(int v)
{
	num++;
	heap[num] = v;
	int pos = num;
	while (pos != 1 & heap[pos / 2] < v)
	{
		int tmp = heap[pos];
		heap[pos] = heap[pos / 2];
		heap[pos / 2] = tmp;
		pos = pos / 2;
	}
}

int remove()
{
	int res = heap[1];
	heap[1] = heap[num];
	num--;
	int pos = 1;
	while (pos * 2 <= num)
	{
		int max_p = max(pos, pos * 2, pos * 2 + 1);
		if (max_p != pos)
		{
			int tmp = heap[pos];
			heap[pos] = heap[max_p];
			heap[max_p] = tmp;
			pos = max_p;
		}
		else
		{
			break;
		}
	}
	return res;
}

int main()
{
	int n;
	char c;
	int v;
	cin >> n;
	num = 0;
	while (n--)
	{
		cin >> c;
		if (c == 'A')
		{
			cin >> v;
			add(v);
		}
		else
		{
			cout << remove() << endl;
		}
	}
	return 0;
}