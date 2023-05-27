#include<bits/stdc++.h>
using namespace std;
int T,opt,x,c,m,n,q;
int a[1010][1010];
main()
{
    freopen(paint,"w",stdin);
    freopen(paint,"r",stdout);
    cin>>T;
    while(T!=0)
    {
        cin>>n>>m>>q;
        while(q--)
        {
            cin>>opt>>x>>c;
            if(opt)
            {
                for(int i=1;i<=m;i++)
                a[x][i]=c;
            }
            else
            {
                for(int i=1;i<=n;i++)
                a[i][x]=c;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<a[i][j];
            cout<<endl;
        }
        T--;
    }
    return 0;
}
