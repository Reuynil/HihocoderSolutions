#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstring>

#define MAXN 100010
#define MIT map<string,int>::iterator
#define MP pair<string,int>
#define VIT vector<int>::iterator

using namespace std;

map<string, int> id;
string names[MAXN];
int mset[MAXN];
int colors[MAXN];
int q1[MAXN], q2[MAXN]; // 查询的两个名字
vector<int> family[MAXN]; // 家谱
vector<int> query[MAXN];	// 查询 
int query_result[MAXN];
int num;
int n, m;

int find_first_gray(int root)
{
	if (colors[root] == 1)
	{
		return root;
	}
	int gray = find_first_gray(mset[root]);
	mset[root] = gray;
	return gray;
}

int dfs(int root)
{
	colors[root] = 1;
	for (VIT iter = query[root].begin(); iter != query[root].end();++iter)// 涉及到查询
	{
		int qa = q1[*iter];
		int qb = q2[*iter];
		int other = qa == root ? qb : qa;
		if (colors[other] == 1)
		{
			query_result[*iter] = other;
		}
		else if (colors[other] == 2)
		{
			query_result[*iter] = find_first_gray(other);
		}
	}
	for (VIT iter = family[root].begin(); iter != family[root].end(); ++iter)
	{
		int son = dfs(*iter);
	}
	colors[root] = 2;
	return root;
}

int main()
{
	memset(mset, 0, MAXN*sizeof(int));
	cin >> n;
	num = 1;
	for (int i = 0; i < n; ++i)
	{
		string father, son;
		int fid, sid;
		cin >> father >> son;
		fid = id[father];
		sid = id[son];
		if (fid == 0)
		{
			id[father] = num;
			fid = num;
			names[fid] = father;
			mset[fid] = fid;
			colors[fid] = 0;
			num++;
		}
		if (sid == 0)
		{
			id[son] = num;
			sid = num;
			names[sid] = son;
			mset[sid] = sid;
			colors[sid] = 0;
			num++;
		}
		family[fid].push_back(sid);
		mset[sid] = fid;
	}

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string a, b;
		cin >> a >> b;
		q1[i] = id[a];
		q2[i] = id[b];
		query[id[a]].push_back(i);
		query[id[b]].push_back(i);
	}

	dfs(1);

	for (int i = 0; i < m; ++i)
	{
		cout << names[query_result[i]] << endl;
	}

	return 0;
}