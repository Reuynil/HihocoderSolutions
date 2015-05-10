#include <iostream>
#include <list>
#include <queue>
#include <string>

using namespace std;

struct node
{
	char ch;
	int num;
	list<node*> next;
};

class tree
{
public:

	void add(string str)
	{
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			list<node*>::iterator ite = root.next.begin();
			while (ite != root.next.end())
			{
				if ((*ite)->ch == str.at(i))
				{
					break;
				}
				else
				{
					ite++;
				}
			}
			if (ite == root.next.end())
			{
				node* newNode = new node();
				newNode->ch = str.at(i);
				newNode->num = 0;
				root.next.push_back(newNode);
				root = *root.next.back();
			}
			else
			{
				root = *(*ite);
			}
		}
	}

private:
	node root;
};


int main()
{
	int num;
	cin >> num;
	return 0;
}