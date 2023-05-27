#include<bits/stdc++.h>
using namespace std;
int i,n,m,j,t,q,k,l,x,c,opt,a[10005][10005];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    for(int o=1;o<=t;o++)
    {
		memset(a,0,sizeof(a));
        cin>>n>>m>>q;
        for(int d=1;d<=q;d++)
        {
            cin>>opt>>x>>c;
            if(opt==1)
            {
                for(i=1;i<=n;i++)
                {
                    a[i][x]=c;
                }
            }
            else
            {
                for(i=1;i<=m;i++)
                {
                    a[x][i]=c;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
