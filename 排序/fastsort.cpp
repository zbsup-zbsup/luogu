#include <bits/stdc++.h>
using namespace std;
int sorthoare_cpu(int a[],int low,int high)
{
    int flag = a[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        }while (a[i]<flag);
        do
        {
            j--;
        }while (a[j]>flag);
        if(i>=j)
        {
            return j;
        }
        swap(a[i],a[j]);
    }
}
void quicksort_h(int a[],int low,int high)
{
    if(low<high)
    {
        int split = sorthoare_cpu(a,low,high);
        quicksort_h(a,low,split);
        quicksort_h(a,split+1,high);
    }
}
int main()
{
    int a[10],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort_h(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}//ac，第一次写排序算法，快排