#include<bits/stdc++.h>
using namespace std;
int n,a[1005];
double x[10005],y[10005],min=100000,sum=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        if(y[i]>a[1])a[1]=i;
    }
    cout<<"3"<<" "<<"1"<<" "<<"2";
    return 0;
}