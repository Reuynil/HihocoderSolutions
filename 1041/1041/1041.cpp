#include<iostream>

using namespace std;

int T,n,m;
int city[101];
int order[100];
bool temp[100];


bool isChild(int father, int child)
{
	while (city[child] != 0)
	{
		if (city[child] == father)
		{
			return true;
		}
		else
		{
			child = city[child];
		}
	}
	return false;
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
		for (int i = 0; i <= n; i++)
		{
			city[i] = 0;
		}

        int i,j;
        for(int k = 0; k < n-1; k++)
        {
            cin>>i>>j;
            city[j]=i;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>order[i];
        }

        bool find = true;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp[j] = isChild(order[i], order[j]);
			}
			for (int j = 0; j < i; j++)
			{
				if (temp[j])
				{
					find = false;
				}
			}
			int k = i + 1;
			while (k < m && temp[k])
			{
				k++;
			}
			if (k < m)
			{
				for (; k < m; k++)
				{
					if (temp[k])
					{
						find = false;
					}
				}
			}
		}
        if(find)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}