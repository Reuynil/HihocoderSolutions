#include<iostream>

using namespace std;

unsigned int temp[100001];
unsigned int ship[100001];
long long result;

int mergeArray(unsigned int a[], int first, int mid, int last)
{
	int i, j, m, n, k;
	i = first;
	m = mid;
	j = mid + 1;
	n = last;
	k = 0;
	long long reverse = 0;
	long long num_last = 0;
	while (i <= m&&j <= n)
	{
		if (a[i] <= a[j])
		{
			temp[k] = a[i];
			i++;
			reverse += num_last;
		}
		else
		{
			temp[k] = a[j];
			j++;
			num_last++;
		}
		k++;
	}
	for (; i <= m; ++i, ++k)
	{
		temp[k] = a[i];
		reverse += num_last;
	}
	for (; j <= n; ++j, ++k)
	{
		temp[k] = a[j];
	}

	for (k = 0, i = first; i <= last; ++k, ++i)
		a[i] = temp[k];

	return reverse;
}

void mergeSort(unsigned int a[], int i, int j)
{
	if (i<j)
	{
		int mid = (i + j) / 2;
		mergeSort(a, i, mid);
		mergeSort(a, mid + 1, j);
		result += mergeArray(a, i, mid, j);
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> ship[i];
	result = 0;
	mergeSort(ship, 0, N - 1);
	cout << result << endl;
	return 0;
}