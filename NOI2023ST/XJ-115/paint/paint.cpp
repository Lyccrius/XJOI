#include<bits/stdc++.h>
using namespace std;
int opt,n,m,q,t,p[20005][20005],x,c;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int i,j,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        for(i=1;i<=q;i++)
        {
            cin>>opt>>x>>c;
            if(opt==0)
            {
                for(a=1;a<=n;a++)
                {
                    p[x][a]=c;
                }
            }
            else
            {
                if(opt==1)
                {
                    for(b=1;b<=m;b++)
                    {
                        p[b][x]=c;
                    }
                }
            }
            
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cout<<p[i][j]<<" ";
                p[i][j]=0;
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}