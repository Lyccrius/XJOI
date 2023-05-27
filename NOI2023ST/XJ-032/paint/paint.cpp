#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,m,q,opt,a[9005][9005]={0},x,c,i,j;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>m>>q;
        while(q--)
        {
            cin>>opt>>x>>c;
            if(opt==0)
            {
                for(i=1;i<=m;i++)
                {
                    a[x][i]=c;
                }
            }
            if(opt==0)
            {
                for(i=1;i<=m;i++)
                {
                    a[x][i]=c;
                }
            }
            if(opt==1)
            {
                for(i=1;i<=n;i++)
                {
                    a[i][x]=c;
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