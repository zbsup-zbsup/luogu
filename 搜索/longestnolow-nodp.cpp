#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int A[MAXN],N,Ans;
void dfs(int pre,int curr,int currlen) //pre表示当前子序列的最后一个元素，curr表示当前正在考虑的元素的索引，currlen表示当前子序列的长度
{
    if(curr==N+1)//如果当前索引已经超过了数组的长度，说明已经考虑完所有元素，此时需要更新最长非递减子序列的长度Ans
    {
        if(currlen>Ans)//如果当前子序列的长度currlen大于Ans，更新Ans
        {
            Ans=currlen;
        }
        return;
    }
    if(A[curr]>
        pre)
    {
        dfs(A[curr],curr+1,currlen+1);
    }
    if(currlen+N-curr>Ans)
    {
        dfs(pre,curr+1,currlen);
    }
}
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }
    Ans=0;
    A[0]=-(1<<30);
    cout<<"A[0]="<<A[0]<<endl;
    dfs(0,1,0);
    cout<<Ans<<endl;
    return 0;
}