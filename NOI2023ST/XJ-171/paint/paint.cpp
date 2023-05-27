#include<bits/stdc++.h>
using namespace std;int s[10005][10005];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int t,c,n,m,p,opt,x;
    cin>>t;
    while(t--)
    {
        memset(s,0,sizeof(s));
        cin>>n>>m;
        cin>>p;
        while(p--)
        {
        cin>>opt>>x>>c;
        if(opt==1)
        {
            for(int i=1;i<=n;i++)
            s[i][x]=c;
        }
        if(opt==0)
        {
            for(int i=1;i<=m;i++)
            s[x][i]=c;
        }
        
        }
        for(int i=1;i<=n;i++)
        {
        for(int j=1;j<=m;j++)
        cout<<s[i][j];
        cout<<endl;
        }
    }
 return 0;
}