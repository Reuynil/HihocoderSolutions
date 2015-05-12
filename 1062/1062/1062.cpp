#include<iostream>
#include<string>

using namespace std;

class person
{
public:
	person()
	{
		father = -1;
	}
    string name;
    int father;
};

person p[101];
int num = 0;

int temp1[101];
int temp2[101];

int find(string name)
{
    if (num==0)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            if (p[i].name == name)
            {
                return i;
            }
        }
        return -1;
    }
}

int getAncestor(string first,string second)
{
    int firstPerson = find(first);
    int secondPerson = find(second);
    for (int i = 0; i < 101; i++)
    {
        temp1[i] = -1;
        temp2[i] = -1;
    }
    if (firstPerson==-1||secondPerson==-1)
    {
        return -1;
    }
    temp1[0] = firstPerson;
    int num1 = 1;
    while (p[firstPerson].father!=-1)
    {
        temp1[num1] = p[firstPerson].father;
        firstPerson = temp1[num1];
        num1++;
    }
    temp2[0] = secondPerson;
    int num2 = 1;
    while (p[secondPerson].father != -1)
    {
        temp2[num2] = p[secondPerson].father;
        secondPerson = temp2[num2];
        num2++;
    }
    while (temp1[num1]==temp2[num2] && num1>-1 && num2>-1)
    {
        num1--;
        num2--;
    }
    return temp2[++num2];
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string son, father;
        cin >> father >> son;
        int fatherPosition = find(father);
        if (fatherPosition == -1)
        {
            p[num].father=-1;
            p[num].name = father;
            fatherPosition = num;
            num++;
        }
        int sonPosition = find(son);
        if (sonPosition==-1)
        {
            p[num].name = son;
            p[num].father = fatherPosition;
            sonPosition = num;
            num++;
        }
        p[sonPosition].father = fatherPosition;
    }
    string first, second;
    cin >> m;
    while (m--)
    {
        cin >> first >> second;
		if (first==second)
		{
			cout << first << endl;
		}
		else
		{
			int res = getAncestor(first, second);
			if (res != -1)
			{
				cout << p[res].name << endl;
			}
			else
			{
				cout << res << endl;
			}
		}
    }
    return 0;
}
