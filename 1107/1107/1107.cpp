#include<iostream>
#include<string>
#include<list>

using namespace std;

struct trieNode
{
	char letter;
	int prefix;
	list<trieNode*> next;
};

class trieTree
{
public:
	trieTree()
	{
		root = new trieNode;
		root->letter = '$';
		root->prefix = 0;
		sppNum = 0;
	}

	void add(string word) 
	{
		trieNode* pre = root;
		list<trieNode*>::iterator candicate = pre->next.begin();
		pre->prefix++;
		bool find = false;
		for (int i = 0; i < word.length(); i++)
		{
			while (candicate != pre->next.end())
			{
				if ((*candicate)->letter == word[i])
				{
					(*candicate)->prefix ++;
					pre = (*candicate);
					candicate = pre->next.begin();
					find = true;
					break;
				}
				else
				{
					candicate++;
				}
			}
			if (!find)
			{
				trieNode* tmp = new trieNode;
				tmp->letter = word[i];
				tmp->prefix = 1;
				pre->next.push_back(tmp);
				pre = tmp;
				candicate = pre->next.begin();
			}
			find = false;
		}
	}

	void treeTraversal(trieNode* rt)
	{
		if (rt->prefix > 5)
		{
			list<trieNode*>::iterator it = rt->next.begin();
			while (it != rt->next.end())
			{
				treeTraversal(*it);
				it++;
			}
		}
		else
		{
			sppNum++;
		}
	}

	//void print(trieNode* rt)
	//{
	//	cout << rt->letter << " " << rt->prefix << endl;
	//	list<trieNode*>::iterator it = rt->next.begin();
	//	while (it != rt->next.end())
	//	{
	//		print(*it);
	//		it++;
	//	}
	//}

	//void selfPrint()
	//{
	//	print(root);
	//}

	int getSppNum()
	{
		treeTraversal(root);
		return sppNum;
	}

private:
	trieNode* root;
	int sppNum;
};


int main()
{
	int num;
	cin >> num;
	string query;
	trieTree tree;
	while (num--)
	{
		cin >> query;
		tree.add(query);
	}
	cout << tree.getSppNum();
	//tree.selfPrint();
	return 0;
}