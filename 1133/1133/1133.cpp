#include<iostream>

using namespace std;

int N, K;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int binarySearch(int data[], int L, int R, int sought_index)
{
	int head = L;
	int tail = R;
	int m = data[sought_index];
	while (head != tail)
	{
		for (; head < tail&&data[head] < m; ++head);
		for (; tail > head&&data[tail] > m; --tail);
		
		if (head != tail)
			swap(data[head], data[tail]);
	}
	if (head == sought_index)
		return data[head];
	else if (head < sought_index)
		binarySearch(data, head, R, sought_index);
	else
		binarySearch(data, L, head, sought_index);
}

int main()
{
	cin >> N >> K;
	int *data = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> data[i];
	}
	cout << binarySearch(data, 0, N - 1, K - 1) << endl;
	delete[] data;
	return 0;
}