#include <bits/stdc++.h>
using namespace std;
int a[11451],x[11451],y[11451],event1[11451],event2[114514],v[11451];
int main()
{
    int sid;
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    
    cin>>sid;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>x[i]>>y[i];
    }
    int sum=0;
    for(int i=1;i<=k;i++)
    {
        sum+=y[i];
    }
    for(int i=1;i<=m;i++)
    {
        int c;
        cin>>c;
        if(c==1)
        {
        cin>>event1[i]>>v[i]; cout<<sum+v[i]<<" ";}
        else {cin>>event2[i];cout<<sum<<" ";}
    }

    return 0;
}