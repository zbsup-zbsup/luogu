#include <bits/stdc++.h>
using namespace std;
int n;
int x[105];
int anss=0;
bool place(int t)
{
    bool ok = 1;
    for(int j=1;j<t;j++)
    {
        if(x[t]==x[j]||t-j==fabs(x[t]-x[j]))
        {
            ok=0;
            break;
        }
    }
    return ok;
}

void backtrack(int t)
{
    if(t>n)//如果当前位置为n，则表示已经找到了问题的一个解
    {
	    anss++;
	    for(int i=1;i<=n;i++)//打印选择的路径
	        cout<<x[i]<<" ";
	    cout<<endl;
	    cout<<"-----------"<<endl;
       }
       else
               for(int i=1;i<=n;i++)//分别判断n个分支,特别注意i不要定义为全局变量,否则递归调用有问题
	{
	      x[t]=i;
	      if(place(t))backtrack(t+1);//如果不冲突的话进行下一行的搜索	
	}
}
int main()
{
    cout<<"请输入皇后的个数n:";
    cin>>n;
    anss=0;
    backtrack(1);
    cout<<"答案的个数是:"<<anss<<endl;
    return 0;
}