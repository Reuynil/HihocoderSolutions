/* 扩展欧几里得算法*/

#include<iostream>

using namespace std;

long gcd(long n,long m)
{
	long a = n >= m ? n : m;
	long b = n <= m ? n : m;
	long c = a % b;
	if(c == 0)
		return b;
	else
		return gcd(b,c);
}

void extend_gcd(long a,long b,long& x, long& y)
{
	if( a % b ==0){
		x = 0;
		y = 1;
	}else{
		extend_gcd(b,a % b, x, y);
		long temp = x;
		x = y;
		y = temp - (a / b) * y;
	}
}

long solve(long s1,long s2,long v1,long v2,long m)
{
	long a = v1 - v2;
	long b = m;
	long c = s2 - s1;
	
	if(a < 0)
		a += m;

	long d = gcd(a, b);

	if(c % d != 0)
		return -1;

	a /= d;
	b /= d;
	c /= d;

	long x, y;
	extend_gcd(a,b,x,y);
	x = (x * c) % b;
	while(x < 0)
		x += b;

	return x;
}

int main()
{
	long s1, s2, v1, v2, m;
	cin>>s1>>s2>>v1>>v2>>m;
	cout<<solve(s1,s2,v1,v2,m)<<endl;
	return 0;
}