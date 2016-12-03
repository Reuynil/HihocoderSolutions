#include<iostream>
#include<cmath>

using namespace std;

long modulo = pow(10, 9) + 7;

//Return the digit of the given number.
int digit(long num)
{
	int res = 0;
	if(num == 0)
	{
		res = 1;
	}
	else
	{
		while(num != 0)
		{
			res++;
			num = num / 10;
		}
	}
	return res;
}

//True means even, and false means odd.
bool parity(long num)
{
	if(num %2 == 0)
		return true;
	else
		return false;
}

//Calculate alternating sum.
int cas(long num)
{
	int l = 0;
	int n[20];
	while (num != 0)
	{
		n[l] = num % 10;
		num = num / 10;
		l++;
	}
	l--;
	int res = n[l];
	bool flag = true;
	for (int i = l - 1; i >= 0; i--)
	{
		if (flag)
		{
			res = res - n[i];
		}
		else
		{
			res = res + n[i];
		}
		flag = !flag;
	}
	return res;
}

int sum(long begin, long end, int find)
{
	int digit_begin = digit(begin);
	int digit_end = digit(end);
	int ss, ss_temp;
	long match = 0;
	for(int i = digit_begin; i <= digit_end; i++)
	{
		long j = pow(10, i - 1);
		if(begin > j)
		{
			j = begin;
			ss_temp = cas(begin);
		}
		else
		{
			ss_temp = 1;
		}/*
		if (ss_temp == find)
		{
			match = (match + j) % modulo;
			cout << j << endl;	//
		}*/

		//check
		if (ss_temp != cas(j))
		{
			cout << "j:\t" << j << "\n"
				<< "ss_temp:\t" << ss_temp << "\n"
				<< "cas(j):\t" << cas(j) << endl;
			return -1;
		}

		j++;
		while(j < pow(10, i) && j <= end)
		{
			if(parity(i))
			{
				if(j % 10 == 0)
				{
					ss = ss_temp + 10;
				}
				else
				{
					ss = ss_temp - 1;
				}
			}
			else
			{	if(j % 10 == 0)
				{
					ss = ss_temp - 10;
				}
				else
				{
					ss = ss_temp + 1;
				}
			}
			ss_temp = ss;/*
			if(ss == find)
			{
				match = (match + j) % modulo;
				cout << j << endl;	//
			}*/

			//check
			if (ss_temp != cas(j))
			{
				cout << "j:\t" << j << "\n"
					<< "ss_temp:\t" << ss_temp << "\n"
					<< "cas(j):\t" << cas(j) << endl;
				return -1;
			}

			j++;
		}
	}
	return match;
}


int main()
{
	long l,k,r;
	while (cin >> l >> k >> r)
	{
		cout << "sum:\t" << sum(l, k, r) << endl;
	}
	return 0;
}