#include<iostream>

using namespace std;

//�ж�child�Ƿ�Ϊfather�������ڵ�
bool isAncestor(int* tree, int father, int child)
{
    while (tree[child] != child)
    {
        child = tree[child];
        if (father == child)
            return true;
    }
    return false;
}

bool judge(int* tree, int* array, int start, int end)
{
    if (start >= end)//���нڵ㶼��������
        return true;
    int k = start + 1;//��ǰ�ڵ�����һ���ڵ�
    //���μ��㵱ǰ�ڵ�start�����Ľڵ��Ƿ�Ϊ���������ڵ㣨��Щ�ڵ������������ģ�
    while (k <= end && isAncestor(tree, array[start], array[k]))
    {
        k++;
    }
    //�����������еĽڵ�����start�������ڵ�,˵���ýڵ����Ѿ�ͨ�����飬Ȼ���ж���һ����ǰ�ڵ㣨start+1��
    if (k >= end)
    {
        return judge(tree, array, start + 1, end);
    }
    int v = k + 1;
    //�жϺ����Ľڵ㣨�����������ڵ��⣬k������һ�����������ڵ㣩
    //�Ƿ�Ϊstart�������ڵ㣬�����ǣ�˵������һ���������������ڵ㣬
    //ֱ��return false
    while (v <= end)
    {
        if (!isAncestor(tree, array[start], array[v]))
        {
            return false;
        }
        v++;
    }
    //start�Ѿ��������ˣ������жϺ����Ľڵ㣨start+1��
    return judge(tree, array, start+1,end);
}

int main()
{

    int T,n,m;
    cin>>T;
    for (int i = 0; i < T; i++)
    {
        cin>>n;
        int* tree = new int[n + 1];
        tree[1] = 1;
        int father,child;
        for (int j = 0; j < n - 1; j++)
        {
            cin>>father>>child;
            tree[child] = father;
        }
            cin>>m;
        int* array = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin>>array[j];
        }
        if (judge(tree, array, 0, m-1))
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
