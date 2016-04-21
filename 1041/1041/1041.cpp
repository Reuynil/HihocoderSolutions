#include<iostream>

using namespace std;


//判断child是否为father的子孙节点
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
    if (start >= end)//所有节点都检查完了
        return true;
    int k = start + 1;//当前节点的下一个节点
    //依次计算当前节点start后面的节点是否为它的子孙节点（这些节点必须是连续的） 
    while (k <= end && isAncestor(tree, array[start], array[k])) 
    {
        k++; 
    } 
    //如果后面所有的节点均是start的子孙节点,说明该节点的已经通过检查，然后判断下一个当前节点（start+1）
    if (k >= end) 
    {  
        return judge(tree, array, start + 1, end); 
    }  
    int v = k + 1; 
    //判断后面的节点（除连续子孙节点外，k是最后一个连续子孙节点）
    //是否为start的子孙节点，如果是，说明存在一个非连续的子孙节点，
    //直接return false  
    while (v <= end)
    { 
        if (!isAncestor(tree, array[start], array[v])) 
        { 
            return false;  
        }  
        v++;  
    }  
    //start已经检查完了，用来判断后面的节点（start+1） 
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
