#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,temp,temp2;
    long long min=10e7;
    cin>>n;
    int list2[n],list3[n];
    double list[n][2],lim=10e7;
    for(int i=0;i<n;i++)list2[i]=i+1;
    for(int i=0;i<n;i++)
    {
        cin>>list[i][0]>>list[i][1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(list[i][0]<=list[j][0]&&list[i][1]<=list[j][1]){
                temp=list2[i];
                list2[i]=list2[j];
                list2[j]=temp;
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(sqrt(pow(list[i][0]-list[j][0],2)+pow(list[i][1]-list[j][1],2))<lim)
            lim=sqrt(pow(list[i][0]-list[j][0],2)+pow(list[i][1]-list[j][1],2));
            temp=list2[i];
            temp2=list2[j];
        }
        list3[i]=temp;
        list3[i+1]=temp2;
    }
    for(int i=0;i<n;i++)
    {
        cout<<list3[i]<<" ";
    }
    return 0;
}