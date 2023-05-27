#include<bits/stdc++.h>
using namespace std;
int a[100005][100005];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int i,j,n,p,m,x,c,o,t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>m>>p;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                cin>>a[i][j];
                a[i][j]=0;
            }


        for(i=1;i<=p;i++)
        {
            cin>>o>>x>>c;
            if(o==1)
            {
                for(j=1;j<=n;j++)
                    a[j][x]=c;
            }
            if(o==0)
            {
                for(j=1;j<=m;j++)
                    a[x][j]=c;
            }
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            cout<<a[i][j]<<" ";
    }
    return 0;
}
