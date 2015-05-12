#include <iostream>
#include <list>
#include <string>

#define LNI list<node*>::iterator

using namespace std;

struct node
{
	char ch;
	int num;
	node* parent;
	list<node*> next;
};

class tree
{
public:
	tree()
	{
		root.ch = '#';
		root.num = 0;
		root.parent = NULL;
	}

	void add(string str)
	{
		int len = str.length();
		node* begin = &root;
		for (int i = 0; i < len; i++)
		{
			LNI iter = begin->next.begin();

			while (iter != begin->next.end() && (*iter)->ch != str.at(i))
			{
				iter++;
			}

			if (iter == begin->next.end())
			{
				node* newNode = new node;
				newNode->ch = str.at(i);
				newNode->num = 0;
				newNode->parent = begin;
				begin->next.push_back(newNode);
				begin = newNode;
			}
			else
			{
				begin = *iter;
			}
		}
		for (node* i = begin; i != NULL; i = i->parent)
		{
			i->num++;
		}
	}

	int query(string word)
	{
		int num = 0;
		node* begin = &root;
		node* bt = begin;
		for (int i = 0; i < word.length(); i++)
		{
			LNI iter = begin->next.begin();
			LNI end = begin->next.end();
			while (iter != end)
			{
				if ((*iter)->ch == word.at(i))
				{
					begin = *iter;
					break;
				}
				else
				{
					iter++;
				}
			}
			if (iter == end)
			{
				return 0;
			}
		}
		num = begin->num;
		return num;
	}

private: 
	node root;
};


int main()
{
	int num;
	string word;
	tree Trie;
	cin >> num;
	while (num--)
	{
		cin >> word;
		Trie.add(word);
	}
	cin >> num;
	while (num--)
	{
		cin >> word;
		cout << Trie.query(word) << endl;
	}
	return 0;
}