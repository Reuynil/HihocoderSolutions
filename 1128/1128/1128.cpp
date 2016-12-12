#include<iostream>

using namespace std;

int N, K;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int binarySearch(int data[], int sought)
{
	int head = 0;
	int tail = N - 1;
	while(true)
	{
		for (; head < tail && data[head] < sought; ++head);
		for (; tail > head && data[tail] > sought; --tail);
		if (head != tail)
			swap(data[head], data[tail]);
		else
			break;
	}
	if (sought == data[head])
		return head + 1;
	else
		return -1;
}

int main()
{
	cin >> N >> K;
	int *data = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> data[i];
	cout << binarySearch(data, K) << endl;
	delete[] data;
	return 0;
}