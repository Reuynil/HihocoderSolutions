#include<iostream>
#include<cmath>

using namespace std;

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
int parity(long num)
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

int sum(int begin, int end, int find)
{
	int digit_begin = digit(begin);
	int digit_end = digit(end);
	int ss, ss_temp;
	long match = 0;
	for(int i = digit_begin; i <= digit_begin; i++)
	{
		int ss_temp;
		int j = pow(10, i - 1);
		if(begin > j)
		{
			j = begin;
			ss_temp = cas(begin);
		}
		else
		{
			ss_temp = 1;
		}
		while(j < pow(10, i))
		{
			if(parity(j))
			{
				if(j % 10 == 0)
				{
				//	ss = 
				}
				else
				{
					ss = ss_temp + 1;
				}
			}
			else
			{	if(j % 10 == 0)
				{
				//	ss = 
				}
				else
				{
					ss = ss_temp - 1;
				}
			}
			ss_temp = ss;
			if(ss == find)
			{
				match = match + j;
			}
			j++;
		}
	}
	return match;
}


int main()
{
	//int l,k,r;
	//cin>>l>>k>>r;
	cout << cas(321) << endl;
	return 0;
}