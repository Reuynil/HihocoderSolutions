#include<iostream>
#include<string>
#include<list>
#include<algorithm>

using namespace std;

class person
{
public:
	person(string n, string s)
	{
		name = n;
		superior = s;
	}
	string getName()
	{
		return name;
	}
	string getSuperior()
	{
		return superior;
	}
	void setName(string n)
	{
		name = n;
	}
	void setSuperior(string s)
	{
		superior = s;
	}
private:
	string name;
	string superior;
};

class findByName
{
public:
	findByName(string str)
	{
		test = str;
	}
	bool operator()(person& p)
	{
		if (p.getName().compare(test) == 0)
			return true;
		else
			return false;
	}
private:
	string test;
};

list<person> v;

void meger(string name1, string name2)
{
	list<person>::iterator ite1 = find_if(v.begin(), v.end(), findByName(name1));
	list<person>::iterator ite1_ = ite1;
	list<person>::iterator ite2 = find_if(v.begin(), v.end(), findByName(name2));
	list<person>::iterator ite2_ = ite2;
	if (ite1!=v.end()&&ite2!=v.end())
	{
		while (ite1->getName() != ite1->getSuperior())
		{
			ite1 = find_if(v.begin(), v.end(), findByName(ite1->getSuperior()));
		}
		ite1_->setSuperior(ite1->getName());
		while (ite2->getName() != ite2->getSuperior())
		{
			ite2 = find_if(v.begin(), v.end(), findByName(ite2->getSuperior()));
		}
		ite2_->setSuperior(ite1->getName());
		ite2->setSuperior(ite1->getName());
	}
	else if (ite1 != v.end() && ite2 == v.end())
	{
		while (ite1->getSuperior()!=ite1->getName())
		{
			ite1 = find_if(v.begin(), v.end(), findByName(ite1->getSuperior()));
		}
		ite1_->setSuperior(ite1->getName());
		person p(name2, ite1->getName());
		v.push_back(p);
	}
	else if (ite1==v.end()&&ite2!=v.end())
	{
		while (ite2->getSuperior() != ite2->getName())
		{
			ite2 = find_if(v.begin(), v.end(), findByName(ite2->getSuperior()));
		}
		ite2_->setSuperior(ite2->getName());
		person p(name1, ite2->getName());
		v.push_back(p);
	}
	else
	{
		person p1(name1, name1);
		v.push_back(p1);
		person p2(name2, name1);
		v.push_back(p2);
	}
}

int judge(string name1,string name2)
{
	list<person>::iterator ite1 = find_if(v.begin(), v.end(), findByName(name1));
	list<person>::iterator ite1_ = ite1;
	list<person>::iterator ite2 = find_if(v.begin(), v.end(), findByName(name2));
	list<person>::iterator ite2_ = ite2;
	if (ite1==v.end()||ite2==v.end())
	{
		return -1;
	}
	while (ite1->getName()!=ite1->getSuperior())
	{
		ite1 = find_if(v.begin(), v.end(), findByName(ite1->getSuperior()));
	}
	ite1_->setSuperior(ite1->getName());
	while (ite2->getName()!=ite2->getSuperior())
	{
		ite2 = find_if(v.begin(), v.end(), findByName(ite2->getSuperior()));
	}
	ite2_->setSuperior(ite2->getName());
	if (ite1->getName()==ite2->getName())
	{
		return 1;
	}
	else
	{
		return -1;
	}
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
			meger(name1, name2);
		}
		else
		{
			if (judge(name1, name2) == 1)
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