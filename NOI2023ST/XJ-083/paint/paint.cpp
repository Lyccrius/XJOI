#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],n,m,q,t;
int opt,x,c;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++)
        {
            cin>>opt>>x>>c;
            if(opt==0)
            {
                for(int j=1;j<=m;j++)
                {

                    a[x][j]=c;
                }

            }
            if(opt==1)
            {
                for(int j=1;j<=n;j++)
                {

                    a[j][x]=c;
                }

            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
