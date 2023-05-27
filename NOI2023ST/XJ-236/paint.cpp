#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        memset(a,0,sizeof(a));
        for(int i=1;i<=q;i++)
        {
            int opt,x,c;
            cin>>opt>>x>>c;
            if(opt)
                for(int j=1;j<=m;j++)
                    a[j][x]=c;
            else
                for(int j=1;j<=n;j++)
                    a[x][j]=c;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cout<<a[i][j]<<' ';
            cout<<endl;
        }
    }
    return 0;
}
